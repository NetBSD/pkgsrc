/*
 * mtscan - scan a mag tape for record structure
 */

#include <stdlib.h>

#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <sys/file.h>

#if	MACH
#include <mach.h>
#endif

#ifdef	MTIO
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/mtio.h>
#endif

#if	i386 && !defined(BIGBUFFERS)
#define	BUFLEN	(32L * 1024L)
#else
#define	BUFLEN	(64L * 1024L)
#endif

#define	MAXBUF	(256L * 1024L)

#define	BIG	5000

const	char	*tape	= "/dev/rst0";
char		*buf;
int		files	= 1;
long		buflen	= BUFLEN;
int		big	= BIG;
int		quiet	= 0;
char		termcap[1024];

char		*backspace(int);
void		done(int);

extern	int	tgetent(char *, char *);
extern	int	tgetflag(char *);

#define	qprintf	if(!quiet) printf

int
main(
	int argc,
	char * const *argv
) {
	int i;
	int n;
	int mt;
	int eflag	= 0;
	int fflag	= 0;
	int hardcopy	= 1;
	int previous;
	int repeat	= 0;
	int first;
	int preveof	= 0;
	int nfiles	= 0;
	long nrec	= 1000000L;
	long count	= 0;
	char *term;
	extern int optind;
	extern char *optarg;
#ifdef	MTIO
	int rewind	= 0;
	int rewindafter	= 0;
	int unload	= 0;
	int unload_err	= 0;
	struct mtop mtop;
#endif

	if(isatty(fileno(stdout)) && (term = getenv("TERM")) != NULL &&
	   tgetent(termcap, term) > 0)
		hardcopy = tgetflag("hc");
	while((i = getopt(argc, argv, "B:b:eFf:hn:qrsUu")) != -1) {
		switch(i) {

		case 'B':
			big = atoi(optarg);
			break;

		case 'b':
			buflen = atol(optarg);
			if(buflen > MAXBUF) {
				fprintf(stderr,
					"Buffer (%ld) too big, set to %ld\n",
					buflen, MAXBUF);
				buflen = MAXBUF;
			}
			break;

		case 'e':
			eflag++;
			break;

		case 'F':
			fflag++;
			break;

		case 'f':
			nfiles = atoi(optarg);
			break;

		case 'h':
			hardcopy++;
			break;

		case 'n':
			nrec = atol(optarg);
			break;

		case 'q':
			quiet++;
			break;

		case 's':
			hardcopy = 0;
			break;

#ifdef	MTIO
		case 'R':
			rewindafter++;
			break;

		case 'r':
			rewind++;
			break;

		case 'U':
			unload_err++;
			break;

		case 'u':
			unload++;
			break;
#endif

		case '?':
		default:
			fprintf(stderr, "unknown flag '%c'\n", i);
			exit(1);
		}
	}
#if	MACH
	if(vm_allocate(task_self(), (vm_address_t *)&buf, buflen, 1) !=
								KERN_SUCCESS) {
		perror("vm_allocate");
		exit(1);
	}
#else
	buf = malloc(buflen);
	if(buf == NULL) {
		perror("no memory");
		exit(1);
	}
#endif
	if(optind < argc)
		tape = argv[optind++];
	mt = open(tape, O_RDONLY, 0);
	if(mt < 0) {
		perror(tape);
		exit(1);
	}
#ifdef	MTIO
	if(rewind) {
		bzero(&mtop, sizeof(mtop));
		mtop.mt_op = MTREW;
		if(ioctl(mt, MTIOCTOP, &mtop) < 0) {
			perror("MTIOCTOP rewind");
			exit(1);
		}
	}
	if(optind < argc) {
		bzero(&mtop, sizeof(mtop));
		mtop.mt_op = MTFSF;
		mtop.mt_count = atoi(argv[optind++]);
		files += mtop.mt_count;
		if(ioctl(mt, MTIOCTOP, &mtop) < 0) {
			perror("MTIOCTOP skip files");
			exit(1);
		}
	}
#endif
	if(optind < argc) {
		fprintf(stderr, "arg count\n");
		exit(1);
	}
	signal(SIGINT, done);
	i = 0;
	previous = -1;
	first = 1;
	while(count < nrec) {
		n = read(mt, buf, buflen);
		i++;
		count++;
		if(n != previous) {
			if(repeat > 0) {
				qprintf("      \r   same through record %d\n",
									i-1);
				fflush(stdout);
			}
			repeat = 0;
			first = 1;
			previous = -1;
		}
		if(n < 0) {
			if(repeat > 0)
				qprintf("\n");
			qprintf("error record %d", i);
			if(eflag) {
				qprintf(" ignored\n");
				fflush(stdout);
				repeat = 0;
				first = 1;
				previous = -1;
				continue;
			} else {
				qprintf("\n");
				fflush(stdout);
				break;
			}
		}
		if(n == 0) {
			if(repeat > 0)
				qprintf("\n");
			qprintf("End of file %d\n", files);
			fflush(stdout);
			i = 0;
			previous = -1;
			repeat = 0;
			if(preveof && !fflag)
				break;
			if(nfiles && (files >= nfiles))
				break;
			files++;
		} else {
			if(n == previous) {
				repeat++;
				if((n > big || i%10 == 0) && !hardcopy) {
					if(first) {
					    qprintf("   same through record ");
					    first = 0;
					}
					qprintf("%d%s", i, backspace(i));
				}
			} else
				qprintf("record %d is length %d\n", i, n);
			fflush(stdout);
			previous = n;
		}
		preveof = n==0;
	}
	qprintf("\n\n%d file%s read.\n", files, files==1?"":"s");
#ifdef	MTIO
	if(rewindafter) {
		bzero(&mtop, sizeof(mtop));
		mtop.mt_op = MTREW;
		if(ioctl(mt, MTIOCTOP, &mtop) < 0) {
			perror("MTIOCTOP rewind after");
			exit(1);
		}
	}
	if(unload) {
		bzero(&mtop, sizeof(mtop));
		mtop.mt_op = MTOFFL;
		if(ioctl(mt, MTIOCTOP, &mtop) < 0) {
			perror("MTIOCTOP offline");
			exit(1);
		}
	}
#endif
	if(nfiles && (files != nfiles)) {
		if(unload_err) {
			bzero(&mtop, sizeof(mtop));
			mtop.mt_op = MTOFFL;
			if(ioctl(mt, MTIOCTOP, &mtop) < 0) {
				perror("MTIOCTOP offline after error");
				exit(1);
			}
		}
		return(1);
	}
	return(0);
}

char *
backspace(int n) {
	static char bs[32];
	int log10;

	for(log10 = 0; n; n /= 10)
		log10++;
	bs[log10] = '\0';
	while(log10-- > 0)
		bs[log10] = '\010';
	return(bs);
}

void
done(int s) {
	if(s)
		qprintf("\nInterrupted.\n");
	qprintf("\n\n%d file%s read.\n", files, files==1?"":"s");
	fflush(stdout);
	exit(s);
}
