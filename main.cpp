#include <iostream>

using namespace std;

int enter_values(double user_values[], int array_size);

void output_stats(double user_values[], int array_size);

const int MAX_SIZE = 20;

#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

int main()
{
    int input_size = 0;
    double user_values[MAX_SIZE] = {0};


    input_size = enter_values(user_values, MAX_SIZE);

    cout << endl;

    output_stats(user_values, input_size);

return 0;
}

int enter_values(double user_values[], int array_size){

    string input;
    int input_size = 0;

    cout << "Enter a maximum of 20 values (enter 'd' or 'done' to stop): " << endl;

    for (int index = 0; index < MAX_SIZE; index++) {

        getline(cin,input);
        //cout << endl;

        if ((input != "d") && (input != "done")) { // d = 100 in ASCII
            stringstream my_stream(input);
            double my_input = 0;
            my_stream >> my_input;
            user_values[index] = my_input;
            input_size++;
        } else {
            break;
        }
    }
    cout << input_size << endl;
    return input_size;
}

void output_stats(double user_values[], int array_size) {
    double temp = user_values[0];
    double temp2 = user_values[0];
    double no_of_terms, sum, sum2, mean, diff_sq, value, variance = 0;

    for(int i = 0; i < array_size; i++)
    {
        if(user_values[i] > temp)
        temp = user_values[i];

        if((user_values[i] < temp2))
        temp2 = user_values[i];

            sum += user_values[i];
    }

    cout << "The maximum number is: " << temp << endl;
    cout << "The minimum number is: " << temp2 << endl;
    mean = sum / array_size;

    for(int i = 0; i < array_size; i++)
    {

        sum2 += pow(user_values[i] - mean, 2.0);

    }

    variance = sum2 / array_size;

    cout << "The mean is " << mean << " and the standard deviation is " << sqrt(variance) << endl;
}

//DOESNT WORK FOR ONE NUMBER
