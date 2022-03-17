#include <iostream>

using namespace std;

// prototype for functions
bool palindromeFinder (string str, int first, int last);
int checkint (int checkint);

int main()
{
    // initializing variables
    string str;
    int first, second, option = 0;
    char option2 = 'Y';


    // While loop to run menu option until user chooses option 3.
    while (option != 2)
    {

        cout << "Choose A Program: "       << endl
             << "1 - Run the Palindrome"   << endl
             << "2 - Quit "                << endl;

            option = checkint (option); // calls checkint to verify data


        // switch to run the menu options
        switch(option)
        {
            case 1:
                // while loop that allows uses to stay in this program until
                //   choosing the option to not to try again.
                while (option2 == 'Y'  || option2 == 'y')
                {
                    cout << "Enter a string: " ;
                    cin.ignore(); //clears previous cin
                    getline(cin, str); //gets full line with spaces

                    // Calls function palindromeFinder and will return a
                    //    screen output that lets the user know if it's a
                    //    palindrome or not.
                    if (palindromeFinder(str, 0, str.length() - 1))
                        cout << "Is a Palindrome" << endl;
                    else
                        cout << "Not a Palindrome" << endl << endl;

                        // Allows user to enter in another palindrome
                        cout << "Would you like to try another? (Y/N) ";
                        cin >> option2;
                        cout << endl;

                }
                option2 = 'Y'; // Resets option2 for later.
                break;

            case 2: // exits program
                break;

            default: // Gives error if proper input isn't received from user.
                cout << "Please enter in option 1 or 2: " << endl;

                break;
        }

    }

    return 0;
}


//Function that take user input and returns if the value is a palindrome or not.
//Postcondition: Prints out message on the screen if value entered is a
//              palindrome or not.
bool palindromeFinder (string str, int first, int last)
{
    if(str.length() == 1)
        return true;

    else if (first >= last)
        return true;

    else if (str[first] != str[last])
        return false;

    return palindromeFinder(str, first + 1, last - 1);

}

//Function that takes user input and determines the greatest common divisor
//Postcondition: Prints out the greatest common divisor on the screen.
int gcd(int x, int y)
{
    if(y == 0)
        return x;
    else
        return gcd(y, x % y);
}

// Function that check int to verifiy data is being entered in correctly.
// Postcondition: Will return number data that was enter if it was an int.
//                Will return error message if data was not an int.
int checkint (int checkint)
{
    // Do While loop to prevent wrong data from being entered.
    string str;
    bool done;
    do
    {
        cout << "Enter Number Here: ";
        cin >> checkint;
        cout << endl;

        try
        {
            if(!cin)
                throw str = "Input error, please try again. ";
            done = true;
        }

        catch (string s)
        {
            cout << s << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }
    }
    while(!done);

    done = false; // Resets done;

    return checkint;
}
