#ifndef _NBCOMPAT_H
#define _NBCOMPAT_H

#include <nbconfig.h>

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

#if HAVE_FTS_H
# include <fts.h>
#else
# include "fts.h"
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
#endif

#ifndef LIST_EMPTY
#define	LIST_EMPTY(head)		((head)->lh_first == NULL)
#endif

#ifndef LIST_FIRST
#define	LIST_FIRST(head)		((head)->lh_first)
#endif

#ifndef LIST_NEXT
#define	LIST_NEXT(elm, field)		((elm)->field.le_next)
#endif

#if HAVE_SYS_QUEUE_H
# include <sys/queue.h>
#else
#define TAILQ_HEAD(name, type)						\
struct name {								\
	struct type *tqh_first;	/* first element */			\
	struct type **tqh_last;	/* addr of last next element */		\
}

#define TAILQ_HEAD_INITIALIZER(head)					\
	{ NULL, &(head).tqh_first }

#define TAILQ_ENTRY(type)						\
struct {								\
	struct type *tqe_next;	/* next element */			\
	struct type **tqe_prev;	/* address of previous next element */	\
}

#define	TAILQ_INIT(head) do {						\
	(head)->tqh_first = NULL;					\
	(head)->tqh_last = &(head)->tqh_first;				\
} while (/*CONSTCOND*/0)

#define TAILQ_INSERT_HEAD(head, elm, field) do {			\
	if (((elm)->field.tqe_next = (head)->tqh_first) != NULL)	\
		(head)->tqh_first->field.tqe_prev =			\
		    &(elm)->field.tqe_next;				\
	else								\
		(head)->tqh_last = &(elm)->field.tqe_next;		\
	(head)->tqh_first = (elm);					\
	(elm)->field.tqe_prev = &(head)->tqh_first;			\
} while (/*CONSTCOND*/0)

#define TAILQ_INSERT_TAIL(head, elm, field) do {			\
	(elm)->field.tqe_next = NULL;					\
	(elm)->field.tqe_prev = (head)->tqh_last;			\
	*(head)->tqh_last = (elm);					\
	(head)->tqh_last = &(elm)->field.tqe_next;			\
} while (/*CONSTCOND*/0)

#define TAILQ_REMOVE(head, elm, field) do {				\
	if (((elm)->field.tqe_next) != NULL)				\
		(elm)->field.tqe_next->field.tqe_prev = 		\
		    (elm)->field.tqe_prev;				\
	else								\
		(head)->tqh_last = (elm)->field.tqe_prev;		\
	*(elm)->field.tqe_prev = (elm)->field.tqe_next;			\
} while (/*CONSTCOND*/0)

/*
 * Tail queue access methods.
 */
#define	TAILQ_EMPTY(head)		((head)->tqh_first == NULL)
#define	TAILQ_FIRST(head)		((head)->tqh_first)
#define	TAILQ_NEXT(elm, field)		((elm)->field.tqe_next)

#define TAILQ_FOREACH(var, head, field)					\
	for ((var) = ((head)->tqh_first);				\
		(var);							\
		(var) = ((var)->field.tqe_next))
#endif

#if HAVE_ASSERT_H
# include <assert.h>
#endif

#if HAVE_ERR_H
# include <err.h>
#endif

#include <ftpglob.h>

#if HAVE_SYS_MKDEV_H
# include <sys/mkdev.h>
#endif

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

/* not all systems define all of these in tzfile.h */
#if HAVE_TZFILE_H
# include <tzfile.h>
#endif

#ifndef DAYSPERNYEAR
# define DAYSPERNYEAR	365
#endif

#ifndef EPOCH_YEAR
# define EPOCH_YEAR	1970
#endif

#ifndef HOURSPERDAY
# define HOURSPERDAY	24
#endif

#ifndef MINSPERHOUR
# define MINSPERHOUR	60
#endif

#ifndef SECSPERHOUR
# define SECSPERHOUR	3600
#endif

#ifndef SECSPERMIN
# define SECSPERMIN	60
#endif

#ifndef SECSPERDAY
# define SECSPERDAY	86400
#endif

#ifndef TM_YEAR_BASE
# define TM_YEAR_BASE	1900
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

#ifndef HAVE_D_NAMLEN
# define DIRENT_MISSING_D_NAMLEN
#endif

#ifndef HAVE_H_ERRNO_D
extern int	h_errno;
#endif
#define HAVE_H_ERRNO	1		/* XXX: an assumption for now... */

#ifndef HAVE_FCLOSE_D
int	fclose(FILE *);
#endif

#ifndef HAVE_ISBLANK
int     isblank(int);
#endif

#ifndef HAVE_GETPASS_D
char	*getpass(const char *);
#endif

#ifndef HAVE_OPTARG_D
extern char    *optarg;
#endif

#ifndef HAVE_OPTIND_D
extern int	optind;
#endif

#ifndef HAVE_PCLOSE_D
int	pclose(FILE *);
#endif

#ifndef HAVE_ERR
#include <err.h>
#endif

#ifndef HAVE_FGETLN
char   *fgetln(FILE *, size_t *);
#endif

#ifndef HAVE_FSEEKO
int	fseeko(FILE *, off_t, int);
#endif

#ifndef HAVE_FPARSELN
# define FPARSELN_UNESCESC	0x01
# define FPARSELN_UNESCCONT	0x02
# define FPARSELN_UNESCCOMM	0x04
# define FPARSELN_UNESCREST	0x08
# define FPARSELN_UNESCALL	0x0f
char   *fparseln(FILE *, size_t *, size_t *, const char[3], int);
#endif

#ifndef HAVE_INET_NTOP
const char *inet_ntop(int, const void *, char *, size_t);
#endif

#ifndef HAVE_INET_PTON
int inet_pton(int, const char *, void *);
#endif

#ifndef HAVE_MKSTEMP
int	mkstemp(char *);
#endif

#ifndef HAVE_MKDTEMP
char   *mkdtemp(char *);
#endif

#ifndef HAVE_LCHMOD
int	lchmod(const char *, mode_t);
#endif

#ifndef HAVE_LCHOWN
int	lchown(const char *, uid_t, gid_t);
#endif

#ifndef HAVE_SETPROGNAME
const char *getprogname(void);
void	setprogname(const char *);
#endif

#ifndef HAVE_SNPRINTF
int	snprintf(char *, size_t, const char *, ...);
#endif

#ifndef HAVE_STRDUP
char   *strdup(const char *);
#endif

#ifndef HAVE_STRERROR
char   *strerror(int);
#endif

#ifndef HAVE_STRMODE
void strmode(mode_t, char *);
#endif

#if !defined(HAVE_STRPTIME) || !defined(HAVE_STRPTIME_D)
char   *strptime(const char *, const char *, struct tm *);
#endif

#if HAVE_QUAD_SUPPORT
# if !defined(HAVE_STRTOLL) && defined(HAVE_LONG_LONG)
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

#ifndef HAVE_TIMEGM
time_t	timegm(struct tm *);
#endif

#ifndef HAVE_HSTRERROR
char   *strerror(int);
#endif

#ifndef HAVE_STRLCAT
size_t	strlcat(char *, const char *, size_t);
#endif

#ifndef HAVE_STRLCPY
size_t	strlcpy(char *, const char *, size_t);
#endif

#ifndef HAVE_STRSEP
char   *strsep(char **stringp, const char *delim);
#endif

#ifndef HAVE_MEMMOVE
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

#endif /* _NBCOMPAT_H */
