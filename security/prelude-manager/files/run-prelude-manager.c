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
    int s;

    /* Sanity check */
    if (argc > MAX_ARGS)
    {
        error_sys("arg buffer too small");
        exit(-1);
    }

    if (geteuid() != 0)
    {
        error_sys("must be called by root");
        exit(-1);
    }

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

            /* Change working directory to root directory.
               The current working directory could be a mounted
               filesystem; if the daemon stays on a mounted
               filesystem it could prevent the filesystem from
               being umounted. */
            chdir("/");

            /* Clear out file creation mask */
            umask(0);

            /* Close unneeded file descriptors */
            maxfd = (int) sysconf(_SC_OPEN_MAX);
            if (maxfd == -1)
                maxfd = getdtablesize();
            for (s = 3; s < maxfd; s++)
                (void) close(s);

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
