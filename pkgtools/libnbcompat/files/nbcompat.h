#include "config.h"

#include <nbtypes.h>

#include <sys/types.h>
#include <sys/param.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include <netinet/in.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>

#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <netdb.h>
#include <pwd.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#if HAVE_POLL
# if HAVE_POLL_H
#  include <poll.h>
# elif HAVE_SYS_POLL_H
#  include <sys/poll.h>
# endif
#elif HAVE_SELECT
# define USE_SELECT
#else
# error "no poll() or select() found"
#endif

#if HAVE_DIRENT_H
# include <dirent.h>
#else
# define dirent direct
# if HAVE_SYS_NDIR_H
#  include <sys/ndir.h>
# endif
# if HAVE_SYS_DIR_H
#  include <sys/dir.h>
# endif
# if HAVE_NDIR_H
#  include <ndir.h>
# endif
#endif

#if TIME_WITH_SYS_TIME
# include <sys/time.h>
# include <time.h>
#else
# if HAVE_SYS_TIME_H
#  include <sys/time.h>
# else
#  include <time.h>
# endif
#endif

#if HAVE_SYS_QUEUE_H
# include <sys/queue.h>
#else
#define LIST_HEAD(name, type)						\
struct name {								\
	struct type *lh_first;	/* first element */			\
}

#define LIST_HEAD_INITIALIZER(head)					\
	{ NULL }

#define LIST_ENTRY(type)						\
struct {								\
	struct type *le_next;	/* next element */			\
	struct type **le_prev;	/* address of previous next element */	\
}

#define LIST_INSERT_HEAD(head, elm, field) do {				\
	if (((elm)->field.le_next = (head)->lh_first) != NULL)		\
		(head)->lh_first->field.le_prev = &(elm)->field.le_next;\
	(head)->lh_first = (elm);					\
	(elm)->field.le_prev = &(head)->lh_first;			\
} while (/*CONSTCOND*/0)

#define	LIST_INIT(head) do {						\
	(head)->lh_first = NULL;					\
} while (/*CONSTCOND*/0)

#define	LIST_EMPTY(head)		((head)->lh_first == NULL)
#define	LIST_FIRST(head)		((head)->lh_first)
#define	LIST_NEXT(elm, field)		((elm)->field.le_next)
#endif

#if HAVE_ASSERT_H
# include <assert.h>
#endif

#if HAVE_ERR_H
# include <err.h>
#endif

#include "ftpglob.h"

#if HAVE_SYS_MOUNT_H
# include <sys/mount.h>
#endif

#if HAVE_PATHS_H
# include <paths.h>
#endif
#ifndef _PATH_BSHELL
#define _PATH_BSHELL	"/bin/sh"
#endif
#ifndef _PATH_TMP
#define _PATH_TMP	"/tmp/"
#endif

#if HAVE_STRINGLIST_H
# include <stringlist.h>
#else
typedef struct _stringlist {
	char	**sl_str;
	size_t	  sl_max;
	size_t	  sl_cur;
} StringList;

StringList *sl_init(void);
int	 sl_add(StringList *, char *);
void	 sl_free(StringList *, int);
char	*sl_find(StringList *, char *);
#endif

#if HAVE_TERMCAP_H
# include <termcap.h>
#else
int	 tgetent(char *, const char *);
char	*tgetstr(const char *, char **);
int	 tgetflag(const char *);
int	 tgetnum(const char *);
char	*tgoto(const char *, int, int);
void	 tputs(const char *, int, int (*)(int));
#endif

#if HAVE_UTIL_H
# include <util.h>
#endif

#if HAVE_LIBUTIL_H
# include <libutil.h>
#endif

#if HAVE_VIS_H
# include <vis.h>
#else
# include "vis.h"
#endif

#if ! HAVE_D_NAMLEN
# define DIRENT_MISSING_D_NAMLEN
#endif

#if ! HAVE_H_ERRNO_D
extern int	h_errno;
#endif
#define HAVE_H_ERRNO	1		/* XXX: an assumption for now... */

#if ! HAVE_FCLOSE_D
int	fclose(FILE *);
#endif

#if ! HAVE_GETPASS_D
char	*getpass(const char *);
#endif

#if ! HAVE_OPTARG_D
extern char    *optarg;
#endif

#if ! HAVE_OPTIND_D
extern int	optind;
#endif

#if ! HAVE_PCLOSE_D
int	pclose(FILE *);
#endif

#if ! HAVE_ERR
void	err(int, const char *, ...);
void	errx(int, const char *, ...);
void	warn(const char *, ...);
void	warnx(const char *, ...);
#endif

#if ! HAVE_FGETLN
char   *fgetln(FILE *, size_t *);
#endif

#if ! HAVE_FSEEKO
int	fseeko(FILE *, off_t, int);
#endif

#if ! HAVE_FPARSELN
# define FPARSELN_UNESCESC	0x01
# define FPARSELN_UNESCCONT	0x02
# define FPARSELN_UNESCCOMM	0x04
# define FPARSELN_UNESCREST	0x08
# define FPARSELN_UNESCALL	0x0f
char   *fparseln(FILE *, size_t *, size_t *, const char[3], int);
#endif

#if ! HAVE_INET_NTOP
const char *inet_ntop(int, const void *, char *, size_t);
#endif

#if ! HAVE_INET_PTON
int inet_pton(int, const char *, void *);
#endif

#if ! HAVE_MKSTEMP
int	mkstemp(char *);
#endif

#if ! HAVE_SETPROGNAME
const char *getprogname(void);
void	setprogname(const char *);
#endif

#if ! HAVE_SNPRINTF
int	snprintf(char *, size_t, const char *, ...);
#endif

#if ! HAVE_STRDUP
char   *strdup(const char *);
#endif

#if ! HAVE_STRERROR
char   *strerror(int);
#endif

#if ! HAVE_STRPTIME || ! HAVE_STRPTIME_D
char   *strptime(const char *, const char *, struct tm *);
#endif

#if HAVE_QUAD_SUPPORT
# if ! HAVE_STRTOLL && HAVE_LONG_LONG
long long strtoll(const char *, char **, int);
#  if ! defined(QUAD_MIN)
#   define QUAD_MIN	(-0x7fffffffffffffffL-1)
#  endif
#  if ! defined(QUAD_MAX)
#   define QUAD_MAX	(0x7fffffffffffffffL)
#  endif
# endif
#else	/* ! HAVE_QUAD_SUPPORT */
# define NO_LONG_LONG	1
#endif	/* ! HAVE_QUAD_SUPPORT */

#if ! HAVE_TIMEGM
time_t	timegm(struct tm *);
#endif

#if ! HAVE_HSTRERROR
char   *strerror(int);
#endif

#if ! HAVE_STRLCAT
size_t	strlcat(char *, const char *, size_t);
#endif

#if ! HAVE_STRLCPY
size_t	strlcpy(char *, const char *, size_t);
#endif

#if ! HAVE_STRSEP
char   *strsep(char **stringp, const char *delim);
#endif

#if ! HAVE_MEMMOVE
# define memmove(a,b,c)	bcopy((b),(a),(c))
	/* XXX: add others #defines for borken systems? */
#endif

#if HAVE_GETPASSPHRASE
# define getpass getpassphrase
#endif

#if ! defined(MIN)
# define MIN(a, b)	((a) < (b) ? (a) : (b))
#endif
#if ! defined(MAX)
# define MAX(a, b)	((a) < (b) ? (b) : (a))
#endif

#if ! defined(timersub)
# define timersub(tvp, uvp, vvp)					\
	do {								\
		(vvp)->tv_sec = (tvp)->tv_sec - (uvp)->tv_sec;		\
		(vvp)->tv_usec = (tvp)->tv_usec - (uvp)->tv_usec;	\
		if ((vvp)->tv_usec < 0) {				\
			(vvp)->tv_sec--;				\
			(vvp)->tv_usec += 1000000;			\
		}							\
	} while (0)
#endif

#if ! defined(S_ISLNK)
# define S_ISLNK(m)	((m & S_IFMT) == S_IFLNK)
#endif

#if ! defined(ALLPERMS)
# define ALLPERMS (S_ISUID|S_ISGID|S_ISVTX|S_IRWXU|S_IRWXG|S_IRWXO)
#endif

#define DAYSPERNYEAR  365
#define	EPOCH_YEAR	1970
#define HOURSPERDAY    24
#define MINSPERHOUR    60
#define	SECSPERHOUR	3600
#define SECSPERMIN     60
#define	SECSPERDAY	86400
#define	TM_YEAR_BASE	1900
