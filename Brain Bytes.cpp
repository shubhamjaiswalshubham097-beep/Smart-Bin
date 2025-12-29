#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   // for sleep()

int pos = 20;
long duration;
float distance;

int main()
{
    printf("Smart Dustbin Simulation Started\n");
    printf("Initial Servo Position: %d degrees\n", pos);

    while (1)
    {
        printf("\nEnter echo duration (in microseconds): ");
        scanf("%ld", &duration);

        // Distance calculation (same as Arduino logic)
        distance = 0.034 * (duration / 2.0);

        printf("Distance detected: %.2f cm\n", distance);

        if (distance < 27)
        {
            printf("Object detected!\n");
            printf("LED: ON\n");
            printf("Servo rotating to %d degrees (Lid Open)\n", pos + 160);
            sleep(1);
        }
        else
        {
            printf("No object detected.\n");
            printf("LED: OFF\n");
            printf("Servo at %d degrees (Lid Closed)\n", pos);
        }

        sleep(1);
    }

    return 0;
}

