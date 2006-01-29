#define PRELUDE_MANAGER_USER "@PRELUDE_USER@"
#define PRELUDE_MANAGER_PATH "@PREFIX@/bin/prelude-manager"
#define MAXMAXFD 256

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pwd.h>
#include <syslog.h>
#include <sys/resource.h>

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
    snprintf(msg, sizeof(msg), "run-prelude-manager : %s : %s", str, strerror(errno));
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

static int
fdlim_get(int hard)
{
    struct rlimit rlfd;

    if (getrlimit(RLIMIT_NOFILE, &rlfd) < 0)
        return (-1);
    if ((hard ? rlfd.rlim_max : rlfd.rlim_cur) == RLIM_INFINITY)
        return sysconf(_SC_OPEN_MAX);
    else
        return hard ? rlfd.rlim_max : rlfd.rlim_cur;
}

static int
fdlim_set(int lim)
{
    struct rlimit rlfd;

    if (lim <= 0)
        return (-1);
    if (getrlimit(RLIMIT_NOFILE, &rlfd) < 0)
        return (-1);
    rlfd.rlim_cur = lim;
    if (setrlimit(RLIMIT_NOFILE, &rlfd) < 0)
        return (-1);
    return (0);
}

int main (int argc, char **argv )

{

    pid_t pid;
    uid_t UID;
    gid_t GID;
    pid_t pidwait;
    int waitstat;
    int maxfd;

    /* Sanity check */
    if (argc > MAX_ARGS)
    {
        error_sys("arg buffer too small");
        exit(-1);
    }
    /*
        if (getpid() != 0)
        {
            error_sys("must be called by root");
            exit(-1);
        }
    */

    /* fork child that will become prelude-manager */
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

            if (!obtainUIDandGID(PRELUDE_MANAGER_USER, &UID, &GID))
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

            /* Increase limit on number of open file descriptors if necessary */
            maxfd = fdlim_get(1);
            if (maxfd < 0)
                error_sys("fdlim_get: bad value");
            if (maxfd > MAXMAXFD)
                maxfd = MAXMAXFD;
            if (maxfd > fdlim_get(0))
                fdlim_set(maxfd);


            /* Build calling argv */
            args[0] = PRELUDE_MANAGER_PATH;
            for (i=1;i<argc;i++)
            {
                args[i] = argv[i];
            }
            args[i++] = NULL;

            /* Finally transform self into prelude-manager */
            if (execvp(PRELUDE_MANAGER_PATH, args) < 0)
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
