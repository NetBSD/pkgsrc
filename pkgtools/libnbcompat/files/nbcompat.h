/*	$NetBSD: nbcompat.h,v 1.33 2004/04/20 12:13:05 grant Exp $	*/

/*-
 * Copyright (c) 2003 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *        This product includes software developed by the NetBSD
 *        Foundation, Inc. and its contributors.
 * 4. Neither the name of The NetBSD Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _NBCOMPAT_H
#define _NBCOMPAT_H

#include <nbcompat/nbconfig.h>
#include <nbcompat/nbtypes.h>

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
#else
# include <nbcompat/poll.h>
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
# include <nbcompat/fts.h>
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
#endif /* HAVE_SYS_QUEUE_H */

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
#endif /* HAVE_SYS_QUEUE_H */

#ifndef TAILQ_HEAD_INITIALIZER
#define TAILQ_HEAD_INITIALIZER(head)					\
	{ NULL, &(head).tqh_first }
#endif
#ifndef TAILQ_EMPTY
#define	TAILQ_EMPTY(head)		((head)->tqh_first == NULL)
#endif
#ifndef TAILQ_FIRST
#define	TAILQ_FIRST(head)		((head)->tqh_first)
#endif
#ifndef TAILQ_NEXT
#define	TAILQ_NEXT(elm, field)		((elm)->field.tqe_next)
#endif
#ifndef TAILQ_FOREACH
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
#else
# include <nbcompat/err.h>
#endif

/* always use our glob.h */
#if HAVE_GLOB_H
# undef HAVE_GLOB_H
#endif
#include <nbcompat/glob.h>

#if HAVE_SYS_MKDEV_H
# include <sys/mkdev.h>
# if !defined(makedev) && defined(mkdev)
#  define makedev mkdev
# endif
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

#ifndef _PATH_DEFTAPE
# ifdef DEFTAPE
#  define _PATH_DEFTAPE DEFTAPE
# else
#  define _PATH_DEFTAPE "/dev/tape"
# endif /* DEFTAPE */
#endif /* _PATH_DEFTAPE */

typedef struct _stringlist {
	char	**sl_str;
	size_t	  sl_max;
	size_t	  sl_cur;
} StringList;

StringList *sl_init(void);
int	 sl_add(StringList *, char *);
void	 sl_free(StringList *, int);
char	*sl_find(StringList *, char *);

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

#if HAVE_NBCOMPAT_MD5INIT
# if HAVE_MD5_H
#  undef HAVE_MD5_H
# endif
#endif

#if HAVE_MD5_H
# include <md5.h>
#else
# include <nbcompat/md5.h>
#endif

#if HAVE_RMD160_H
# include <rmd160.h>
#else
# include <nbcompat/rmd160.h>
#endif

#if HAVE_SHA1_H
# include <sha1.h>
#else
# include <nbcompat/sha1.h>
#endif

#if HAVE_NBCOMPAT_VIS
# if HAVE_VIS_H
#  undef HAVE_VIS_H
# endif
#endif

#if HAVE_VIS_H
# include <vis.h>
#else
# include <nbcompat/vis.h>
#endif

#if HAVE_GETOPT_H
# include <getopt.h>
#endif

#if HAVE_NBCOMPAT_GETOPT_LONG
# include <nbcompat/getopt.h>
#endif

#if !HAVE_OPTARG_D
extern char    *optarg;
#endif

#if !HAVE_OPTIND_D
extern int	optind;
#endif

#if !HAVE_D_NAMLEN
# define DIRENT_MISSING_D_NAMLEN
#endif

#if !HAVE_H_ERRNO_D
#ifndef _AIX
extern int	h_errno;
#endif
#endif
#define HAVE_H_ERRNO	1		/* XXX: an assumption for now... */

#if !HAVE_FCLOSE_D
int	fclose(FILE *);
#endif

#if !HAVE_ISBLANK
int     isblank(int);
#endif

#if !HAVE_GETPASS_D
char	*getpass(const char *);
#endif

#if !HAVE_PCLOSE_D
int	pclose(FILE *);
#endif

#if !HAVE_FGETLN
char   *fgetln(FILE *, size_t *);
#endif

#if !HAVE_FSEEKO
int	fseeko(FILE *, off_t, int);
#endif

#if !HAVE_FPARSELN
# define FPARSELN_UNESCESC	0x01
# define FPARSELN_UNESCCONT	0x02
# define FPARSELN_UNESCCOMM	0x04
# define FPARSELN_UNESCREST	0x08
# define FPARSELN_UNESCALL	0x0f
char   *fparseln(FILE *, size_t *, size_t *, const char[3], int);
#endif

#if !HAVE_INET_NTOP
const char *inet_ntop(int, const void *, char *, size_t);
#endif

#if !HAVE_INET_PTON
int inet_pton(int, const char *, void *);
#endif

#if !HAVE_MKSTEMP
int	mkstemp(char *);
#endif

#if !HAVE_MKDTEMP
char   *mkdtemp(char *);
#endif

#if !HAVE_LCHMOD
int	lchmod(const char *, mode_t);
#endif

#if !HAVE_LCHOWN
int	lchown(const char *, uid_t, gid_t);
#endif

#if !HAVE_SETPROGNAME
const char *getprogname(void);
void	setprogname(const char *);
#endif

#if !HAVE_SNPRINTF
int	snprintf(char *, size_t, const char *, ...);
#endif

#if !HAVE_STRDUP
char   *strdup(const char *);
#endif

#if !HAVE_STRERROR
char   *strerror(int);
#endif

#if !HAVE_STRMODE
void strmode(mode_t, char *);
#endif

#if !HAVE_STRPTIME || !HAVE_STRPTIME_D
char   *strptime(const char *, const char *, struct tm *);
#endif

#if HAVE_WORKING_LONG_LONG
# if !defined(HAVE_STRTOLL) && defined(HAVE_LONG_LONG)
long long strtoll(const char *, char **, int);
# endif
# if ! defined(LLONG_MAX)
#  if defined(LONG_LONG_MAX)
#   define LLONG_MAX	LONG_LONG_MAX
#  else
#   define LLONG_MAX	(0x7fffffffffffffffLL)
#  endif
# endif
# if ! defined(LLONG_MIN)
#  if defined(LONG_LONG_MIN)
#   define LLONG_MIN	LONG_LONG_MIN
#  else
#   define LLONG_MIN	(-0x7fffffffffffffffLL-1)
#  endif
# endif
#else	/* ! HAVE_WORKING_LONG_LONG */
# define NO_LONG_LONG	1
#endif	/* ! HAVE_WORKING_LONG_LONG */

#if ! defined(LLONG_MAX)
# define LLONG_MAX	0x7fffffffffffffffLL	/* max long long */
#endif

#if ! defined(ULLONG_MAX)
# define ULLONG_MAX	0xffffffffffffffffULL	/* max unsigned long long */
#endif

#if !HAVE_TIMEGM
time_t	timegm(struct tm *);
#endif

#if !HAVE_HSTRERROR
char   *strerror(int);
#endif

#if !HAVE_STRLCAT
size_t	strlcat(char *, const char *, size_t);
#endif

#if !HAVE_STRLCPY
size_t	strlcpy(char *, const char *, size_t);
#endif

#if !HAVE_STRSEP
char   *strsep(char **stringp, const char *delim);
#endif

#if !HAVE_USER_FROM_UID
const char *user_from_uid(uid_t, int);
#endif

#if !HAVE_GROUP_FROM_GID
const char *group_from_gid(gid_t, int);
#endif

#if !HAVE_UID_FROM_USER
int uid_from_user(const char *, uid_t *);
#endif

#if !HAVE_GID_FROM_GROUP
int gid_from_group(const char *, gid_t *);
#endif

#if HAVE_NBCOMPAT_STATFS
# if HAVE_SYS_STATFS_H
#  undef HAVE_SYS_STATFS_H
# endif
# include <nbcompat/statfs.h>
#endif

#if !HAVE_MEMMOVE
# define memmove(a,b,c)	bcopy((b),(a),(c))
	/* XXX: add others #defines for borken systems? */
#endif

#if HAVE_GETPASSPHRASE
# define getpass getpassphrase
#endif

#if !defined(MIN)
# define MIN(a, b)	((a) < (b) ? (a) : (b))
#endif
#if !defined(MAX)
# define MAX(a, b)	((a) < (b) ? (b) : (a))
#endif

#if !defined(timersub)
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

/* not all systems define all of these in sys/stat.h */
#if !defined(S_ISLNK)
# define S_ISLNK(m)	((m & S_IFMT) == S_IFLNK)
#endif

#if !defined(S_ISTXT)
# define S_ISTXT S_ISVTX
#endif

#if !defined(ALLPERMS)
# define ALLPERMS (S_ISUID|S_ISGID|S_ISTXT|S_IRWXU|S_IRWXG|S_IRWXO)
#endif

/* not all systems define all of these in limits.h */
#ifndef GID_MAX
# define GID_MAX	2147483647U  /* max value for a gid_t (2^31-2) */
#endif

#ifndef UID_MAX
# define UID_MAX	2147483647U  /* max value for a uid_t (2^31-2) */
#endif

#ifndef HAVE_SETMODE
void *setmode(const char *);
#endif

#ifndef HAVE_GETMODE
mode_t getmode(const void *, mode_t);
#endif

#ifndef HAVE_UTIMES
int utimes(const char *, const struct timeval *);
#endif

#endif /* _NBCOMPAT_H */
