/* A simple program to print information about signal handlers */

#include "config.h"
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#ifdef HAVE_STRING_H
# include <string.h>
#else
# include <strings.h>
# define strchr index
# define strrchr rindex
#endif /* HAVE_STRING_H */
#ifdef HAVE_STDLIB_H
# include <stdlib.h>
#endif /* HAVE_STDLIB_H */
#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif /* HAVE_UNISTD_H */

#ifndef SIG_ERR
# define SIG_ERR	((RETSIGTYPE (*)()) -1)
#endif /* SIG_ERR */

/* must be similar to struct Trap in sh.h */
struct signal_info {
	int	signal;
	char	*name;
	char	*mess;
};
struct signal_info siginfo[] = {
	{ 0, "0", "Signal 0" },
#include "siglist.out"
	{ 0, (char *) 0, (char *)0  },
};

int		usage();
#if 0
RETSIGTYPE	sig_catcher();
#endif /* 0 */
char		*signal_name();
#ifndef HAVE_STRERROR
char		*strerror(int);
#endif /* !HAVE_STRERROR */

char	*progname =	"check-sigs";
int	caught_sigs;

int
main(argc, argv)
	int argc;
	char **argv;
{
	extern int	optind;
	extern char	*optarg;
	extern int	errno;

	int		opt;
	int		i;
	int		eno;
	int		report_all = 0;
	RETSIGTYPE	(*f)();
	char		*ofile = (char *) 0;
	char		*s;
	int		wait_forever = 0;

	if (argc > 0 && argv[0] && *argv[0])
		progname = argv[0];

	while ((opt = getopt(argc, argv, "ao:w")) != EOF) {
		switch (opt) {
		case 'a':
			report_all = 1;
			break;

		case 'o':
			ofile = optarg;
			break;

		case 'w':
			wait_forever = 1;
			break;

		default:
			usage(1);
		}
	}

	if (argc != optind)
		usage(0);

	if (ofile && freopen(ofile, "w", stdout) == (FILE *) 0) {
		fprintf(stderr, "%s: Couldn't open output file `%s' - %s\n",
			progname, ofile, strerror(errno));
		exit(1);
	}

	if (!wait_forever) {
		char *blocked = "";
#ifdef POSIX_SIGNALS
		sigset_t mask;

		sigprocmask(SIG_BLOCK, (sigset_t *) 0, &mask);
#endif /* POSIX_SIGNALS */
#ifdef BSD42_SIGNALS
		int mask;

		mask = sigblock(0);
#endif /* BSD42_SIGNALS */
		for (i = 1; i < NSIG; i++) {
			f = signal(i, SIG_DFL);
			eno = errno;
#ifdef BSD42_SIGNALS
			blocked = (mask & sigmask(i)) ? "blocked" : "";
#endif /* BSD42_SIGNALS */
#ifdef POSIX_SIGNALS
			blocked = sigismember(&mask, i) ? "blocked" : "";
#endif /* POSIX_SIGNALS */
			if (f == SIG_DFL && !report_all && !*blocked)
				continue;
			printf("%3d: %7s %30s: ",
				i, blocked, (s = signal_name(i)) ? s : "");
			if (f == SIG_IGN)
				printf("ignored\n");
			else if (f == SIG_ERR)
				printf("error - %s\n", strerror(eno));
			else if (f != SIG_DFL)
				printf("caught - function address %lx\n",
					(long) f);
			else if (report_all)
				printf("default\n");
		}
	}

#if 0	/* code assumes BSD signals - not worth posixizing */
	if (wait_forever) {
		printf("pid is %d\n", getpid());
		sigsetmask(-1L);
		for (i = 0; i < NSIG; i++)
			(void) signal(i, sig_catcher);
		while (1) {
			sigpause(0L);
			for (i = 1; i < NSIG; i++)
				if (caught_sigs & sigmask(i))
					printf("received signal %d - %s\n",
						i,
						(s = signal_name(i)) ? s
								     : "");
			caught_sigs = 0L;
		}
	}
#endif

	return 0;
}

int
usage(verbose)
	int verbose;
{
	fprintf(stderr, "Usage: %s [-?aw] [-o file]\n", progname);
	if (verbose)
		fprintf(stderr, "\
	-a	report on all signals - instead of just non-default signals\n\
	-o f	redirect standard output to file f\n\
	-w	wait forever, reporting all signals sent\n\
");

	exit(1);
	return 0;
}

#if 0
RETSIGTYPE
sig_catcher(sig)
	int sig;
{
	caught_sigs |= sigmask(sig);
	return RETSIGVAL;
}
#endif /* 0 */



char *
signal_name(sig)
	int sig;
{
	static char buf[1024];

#ifdef HAVE_SYS_SIGLIST
# ifndef SYS_SIGLIST_DECLARED
	extern char	*sys_siglist[];
# endif
	/* Use system description, if available... */
	if (sys_siglist[sig] && sys_siglist[sig][0])
		return sys_siglist[sig];
#endif	/* HAVE_SYS_SIGLIST */


	if (sig > 0 && sig < sizeof(siginfo) / sizeof(siginfo[0]) - 1) {
		sprintf(buf, "SIG%s (%s)",
			siginfo[sig].name, siginfo[sig].mess);
		return buf;
	}

	return (char *) 0;
}

#ifndef HAVE_STRERROR
char *
strerror(err)
	int err;
{
	static char	buf[64];
# ifdef HAVE_SYS_ERRLIST
#  ifndef SYS_ERRLIST_DECLARED
	extern int	sys_nerr;
	extern char	*sys_errlist[];
#  endif
	char		*p;

	if (err < 0 || err >= sys_nerr)
		sprintf(p = buf, "Unknown system error %d", err);
	else
		p = sys_errlist[err];
	return p;
# else /* HAVE_SYS_ERRLIST */
	switch (err) {
	  case EINVAL:
		return "Invalid argument";
	  case EACCES:
		return "Permission denied";
	  case ESRCH:
		return "No such process";
	  case EPERM:
		return "Not owner";
	  case ENOENT:
		return "No such file or directory";
	  case ENOTDIR:
		return "Not a directory";
	  case ENOEXEC:
		return "Exec format error";
	  case ENOMEM:
		return "Not enough memory";
	  case E2BIG:
		return "Argument list too long";
	  default:
		sprintf(buf, "Unknown system error %d", err);
		return buf;
	}
# endif /* HAVE_SYS_ERRLIST */
}
#endif /* !HAVE_STRERROR */
