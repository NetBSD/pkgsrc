/* A simple program to print information about process groups */

#include "config.h"
#include <stdio.h>
#include <sys/types.h>
#ifdef HAVE_STDLIB_H
# include <stdlib.h>
#endif /* HAVE_STDLIB_H */
#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif /* HAVE_UNISTD_H */
#ifdef HAVE_FCNTL_H
# include <fcntl.h>
#else /* HAVE_FCNTL_H */
# include <sys/file.h>
#endif /* HAVE_FCNTL_H */

#ifdef BSD_PGRP
# include <sys/ioctl.h>
int
tcgetpgrp(fd)
	int fd;
{
	int r, grp;

	if ((r = ioctl(fd, TIOCGPGRP, &grp)) < 0)
		return r;
	return grp;
}
# define getPGRP()	getpgrp(0)
#else /* BSD_PGRP */
# define getPGRP()	getpgrp()
#endif /* BSD_PGRP */

int	usage();

char	*progname =	"check-pgrp";

int
main(argc, argv)
    int argc;
    char **argv;
{
    extern int	optind;
    extern char	*optarg;

    int		opt;
    int		ttyfd = 0;
    int		my_pgrp, my_pid, my_ppid, tty_pgrp;
    char	*tty_name;
    char	*e;

    if (argc > 0 && argv[0] && *argv[0])
	progname = argv[0];

    while ((opt = getopt(argc, argv, "u:")) != EOF) {
	switch (opt) {
	case 'u':
	    ttyfd = atoi(optarg);
	    break;

	default:
	    usage(1);
	}
    }

    if (optind != argc) {
	    fprintf(stderr, "%s: too many arguments\n", progname);
	    usage(0);
    }

    my_pid = getpid();
    my_ppid = getppid();
    my_pgrp = getPGRP();
    tty_pgrp = tcgetpgrp(ttyfd);
    tty_name = ttyname(ttyfd);

    printf("in %s pgrp\ntty %s (%s)\npid %d, ppid %d, pgrp %d, tty_pgrp %d\n",
	my_pgrp == my_pid ? "my own"
	    : (my_pgrp == my_ppid ? "parent's" : "unknown"),
	tty_name ? tty_name : "(none)",
	tty_pgrp == my_pgrp ? "mine"
	    : (tty_pgrp == my_ppid ? "parent's" : "unknown"),
	my_pid, my_ppid, my_pgrp, tty_pgrp);

    return 0;
}

int
usage(verbose)
    int verbose;
{
    fprintf(stderr, "Usage: %s [-?] [-u fd]\n", progname);
    if (verbose)
	fprintf(stderr, "\
    -u fd	use fd as tty fd (default is 0)\n\
");

    exit(1);
    return 0;
}
