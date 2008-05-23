/* A simple program to check which file descriptors are open and
 * print some info about them.
 */

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
#include "ksh_stat.h"

int	usage();

char	*progname =	"check-fd";

#define MAXFD	256	/* a somewhat arbitrary number */

int
main(argc, argv)
	int argc;
	char **argv;
{
	extern int	optind;

	int		opt;
	int		do_close = 0;
	struct stat	statb;
	int		i;

	if (argc > 0 && argv[0] && *argv[0])
		progname = argv[0];

	while ((opt = getopt(argc, argv, "c")) != EOF) {
		switch (opt) {
		  case 'c':
			do_close = 1;
			break;

		  default:
			usage(1);
		}
	}

	if (optind != argc) {
		fprintf(stderr, "%s: too many arguments\n", progname);
		usage(0);
	}

	if (do_close) {
		for (i = 0; i < MAXFD; i++)
			if (i == 1)
				printf("(can't check 1)\n");
			else if (close(i) >= 0)
				printf("%d was open\n", i);
	} else {
		for (i = 0; i < MAXFD; i++)
			if (fstat(i, &statb) == 0)
				printf(
			    "%d is open (dev/inode %hd/%ld, flags 0x%x)\n",
				i, statb.st_dev, statb.st_ino,
				fcntl(i, F_GETFL, 0));
	}

	return 0;
}

int
usage(verbose)
	int verbose;
{
	fprintf(stderr, "Usage: %s [-?c]\n", progname);
	if (verbose)
		fprintf(stderr, "\
	-c	use close(2) instead of fstat(2) to check for open fds\n\
		(prints dev, inode and fcntl(F_GETFL) flags)\n\
");

	exit(1);
	return 0;
}
