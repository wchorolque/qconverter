#include <QCoreApplication>
#include <QtGui>
#include <QtCore/QTextStream>

#include <cstdlib>

qreal convertCelciusToFahrenheit(qreal);
void printTable(qreal);

void printTable(qreal increment)
{
    QTextStream cout(stdout);

    for (qreal value = 0; value <= 100; value+= increment) {
        qreal fahrenheit = convertCelciusToFahrenheit(value);
        cout << " Celsius: " << value << " -> " << fahrenheit << endl;
    }
}

qreal convertCelciusToFahrenheit(qreal celsius)
{
    return (celsius * 9) / 5 + 32;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    int answer;
    do {
        bool ok;
        qreal celsius =  QInputDialog::getDouble(
                    0,                  // Parent
                    "Celsius Converter",// Title
                    "Celsius:",         // Label
                    0,                  // Value
                    -100,               // Min Value
                    100,                // Max Value
                    1,                  // Decimals
                    &ok                 // Result presed ok or cancel
                    );

        if (true == ok) {
            qreal fahrenheit = convertCelciusToFahrenheit(celsius);
            printTable(5);
            QString response = QString(
                        "The value from celsius %1 to Fahrenheit is %2\n%3")
                    .arg(celsius)
                    .arg(fahrenheit)
                    .arg("Do you want to convert another value?");
            answer = QMessageBox::question(
                        0,                          // Parent
                        "Convert Another Value?",   // Label
                        response,                   // Message
                        QMessageBox::Yes | QMessageBox::No
                        );
        } else {
            break;
        }
    } while  (QMessageBox::Yes == answer);

    return EXIT_SUCCESS;
}
