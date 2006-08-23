#define PREWIKKA_HTTPD_USER "@PREWIKKA_USER@"
#define PREWIKKA_HTTPD_PATH "@PREFIX@/bin/prewikka-httpd"
#define PYTHON "@PYTHONBIN@"

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pwd.h>
#include <syslog.h>

#define MAX_ARGS 40
#ifndef         TRUE
#define         TRUE                            1
#endif                          /* TRUE */

#ifndef         FALSE
#define         FALSE                           0
#endif                          /* FALSE */


void error_sys(char *str)

{
    /* Output error message to syslog */
    char msg[1024];
    snprintf(msg, sizeof(msg), "run-prewikka-httpd : %s : %s", str, strerror(errno));
    syslog(LOG_ALERT, msg);

}


int obtainUIDandGID(const char *name, uid_t *pw_uid, gid_t *pw_gid)
{
    /* Obtain UID and GID from passwd entry identified by name */
    struct passwd *pw_entry;
    char msg[100];

    if ((pw_entry = getpwnam(name)) == NULL)
    {
        snprintf(msg, sizeof(msg), "failed to get password entry for %s", name);
        error_sys(msg);
        return FALSE;
    }
    else
    {
        *pw_uid = pw_entry->pw_uid;
        *pw_gid = pw_entry->pw_gid;
        return TRUE;

    }
}


int main (int argc, char **argv )

{

    pid_t pid;
    uid_t UID;
    gid_t GID;
    pid_t pidwait;
    int waitstat;

    /* Sanity check */
    if (argc > MAX_ARGS)
    {
        error_sys("arg buffer too small");
        exit(-1);
    }

    /* fork child that will become prewikka-httpd */
    if ((pid = fork()) < 0)

        error_sys("fork error");

    else

    {

        if (pid == 0)

        {

            /* We're the child */
            char *args[MAX_ARGS];
            unsigned int i;

            /* Become session leader */
            setsid();

            /* Clear out file creation mask */
            umask(0);

            if (!obtainUIDandGID(PREWIKKA_HTTPD_USER, &UID, &GID))
                exit(-1);

            /* Drop privileges immediately */
            if (setgid(GID) < 0)
            {
                /* It is VERY important to check return
                   value and not continue if setgid fails
                */
                error_sys ("setgid failed");
                exit (-1);
            }

            if (setuid(UID) < 0)
            {
                /* It is VERY important to check return
                   value and not continue if setuid fails
                */
                error_sys ("setuid failed");
                exit (-1);
            }

            /* Build calling argv */
            args[0] = PYTHON;
            args[1] = PREWIKKA_HTTPD_PATH;
            for (i=1;i<argc;i++)
            {
               args[i+1] = argv[i];
               args[i+2] = NULL;
            }

            /* Finally transform self into prewikka-httpd */
            if (execvp(PYTHON, args) < 0)
                error_sys("execve error");
            else
                ; /* avoid if-then ambiguity */
        }

        else

        {
            /* We're the parent
               Terminate
            */
            exit(0);
        }

    }

}
