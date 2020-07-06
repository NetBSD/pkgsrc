/*	$OpenBSD: sh.h,v 1.35 2015/09/10 22:48:58 nicm Exp $	*/
/*	$OpenBSD: shf.h,v 1.6 2005/12/11 18:53:51 deraadt Exp $	*/
/*	$OpenBSD: table.h,v 1.8 2012/02/19 07:52:30 otto Exp $	*/
/*	$OpenBSD: tree.h,v 1.10 2005/03/28 21:28:22 deraadt Exp $	*/
/*	$OpenBSD: expand.h,v 1.7 2015/09/01 13:12:31 tedu Exp $	*/
/*	$OpenBSD: lex.h,v 1.13 2013/03/03 19:11:34 guenther Exp $	*/
/*	$OpenBSD: proto.h,v 1.35 2013/09/04 15:49:19 millert Exp $	*/
/*	$OpenBSD: c_test.h,v 1.4 2004/12/20 11:34:26 otto Exp $	*/
/*	$OpenBSD: tty.h,v 1.5 2004/12/20 11:34:26 otto Exp $	*/

/*-
 * Copyright © 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010,
 *	       2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018,
 *	       2019, 2020
 *	mirabilos <m@mirbsd.org>
 *
 * Provided that these terms and disclaimer and all copyright notices
 * are retained or reproduced in an accompanying document, permission
 * is granted to deal in this work without restriction, including un‐
 * limited rights to use, publicly perform, distribute, sell, modify,
 * merge, give away, or sublicence.
 *
 * This work is provided “AS IS” and WITHOUT WARRANTY of any kind, to
 * the utmost extent permitted by applicable law, neither express nor
 * implied; without malicious intent or gross negligence. In no event
 * may a licensor, author or contributor be held liable for indirect,
 * direct, other damage, loss, or other issues arising in any way out
 * of dealing in the work, even if advised of the possibility of such
 * damage or existence of a defect, except proven that it results out
 * of said person’s immediate fault when using the work as intended.
 */

#ifdef __dietlibc__
/* XXX imake style */
#define _BSD_SOURCE	/* live, BSD, live❣ */
#endif

#if HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif
#include <sys/types.h>
#if HAVE_BOTH_TIME_H
#include <sys/time.h>
#include <time.h>
#elif HAVE_SYS_TIME_H
#include <sys/time.h>
#elif HAVE_TIME_H
#include <time.h>
#endif
#include <sys/ioctl.h>
#if HAVE_SYS_SYSMACROS_H
#include <sys/sysmacros.h>
#endif
#if HAVE_SYS_MKDEV_H
#include <sys/mkdev.h>
#endif
#if HAVE_SYS_MMAN_H
#include <sys/mman.h>
#endif
#if HAVE_SYS_RESOURCE_H
#include <sys/resource.h>
#endif
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#if HAVE_IO_H
#include <io.h>
#endif
#if HAVE_LIBGEN_H
#include <libgen.h>
#endif
#if HAVE_LIBUTIL_H
#include <libutil.h>
#endif
#include <limits.h>
#if HAVE_PATHS_H
#include <paths.h>
#endif
#include <pwd.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#if HAVE_STDINT_H
#include <stdint.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if HAVE_STRINGS_H
#include <strings.h>
#endif
#if HAVE_TERMIOS_H
#include <termios.h>
#else
/* shudder… */
#include <termio.h>
#endif
#ifdef _ISC_UNIX
/* XXX imake style */
#include <sys/sioctl.h>
#endif
#if HAVE_ULIMIT_H
#include <ulimit.h>
#endif
#include <unistd.h>
#if HAVE_VALUES_H
#include <values.h>
#endif
#ifdef MIRBSD_BOOTFLOPPY
#include <wchar.h>
#endif

/* monkey-patch known-bad offsetof versions to quell a warning */
#if (defined(__KLIBC__) || defined(__dietlibc__)) && \
    ((defined(__GNUC__) && (__GNUC__ > 3)) || defined(__NWCC__))
#undef offsetof
#define offsetof(s,e)		__builtin_offsetof(s, e)
#endif

#undef __attribute__
#if HAVE_ATTRIBUTE_BOUNDED
#define MKSH_A_BOUNDED(x,y,z)	__attribute__((__bounded__(x, y, z)))
#else
#define MKSH_A_BOUNDED(x,y,z)	/* nothing */
#endif
#if HAVE_ATTRIBUTE_FORMAT
#define MKSH_A_FORMAT(x,y,z)	__attribute__((__format__(x, y, z)))
#else
#define MKSH_A_FORMAT(x,y,z)	/* nothing */
#endif
#if HAVE_ATTRIBUTE_NORETURN
#define MKSH_A_NORETURN		__attribute__((__noreturn__))
#else
#define MKSH_A_NORETURN		/* nothing */
#endif
#if HAVE_ATTRIBUTE_PURE
#define MKSH_A_PURE		__attribute__((__pure__))
#else
#define MKSH_A_PURE		/* nothing */
#endif
#if HAVE_ATTRIBUTE_UNUSED
#define MKSH_A_UNUSED		__attribute__((__unused__))
#else
#define MKSH_A_UNUSED		/* nothing */
#endif
#if HAVE_ATTRIBUTE_USED
#define MKSH_A_USED		__attribute__((__used__))
#else
#define MKSH_A_USED		/* nothing */
#endif

#if defined(MirBSD) && (MirBSD >= 0x09A1) && \
    defined(__ELF__) && defined(__GNUC__) && \
    !defined(__llvm__) && !defined(__NWCC__)
/*
 * We got usable __IDSTRING __COPYRIGHT __RCSID __SCCSID macros
 * which work for all cases; no need to redefine them using the
 * "portable" macros from below when we might have the "better"
 * gcc+ELF specific macros or other system dependent ones.
 */
#else
#undef __IDSTRING
#undef __IDSTRING_CONCAT
#undef __IDSTRING_EXPAND
#undef __COPYRIGHT
#undef __RCSID
#undef __SCCSID
#define __IDSTRING_CONCAT(l,p)		__LINTED__ ## l ## _ ## p
#define __IDSTRING_EXPAND(l,p)		__IDSTRING_CONCAT(l,p)
#ifdef MKSH_DONT_EMIT_IDSTRING
#define __IDSTRING(prefix,string)	/* nothing */
#elif defined(__ELF__) && defined(__GNUC__) && \
    !(defined(__GNUC__) && defined(__mips16) && (__GNUC__ >= 8)) && \
    !defined(__llvm__) && !defined(__NWCC__) && !defined(NO_ASM)
#define __IDSTRING(prefix,string)				\
	__asm__(".section .comment"				\
	"\n	.ascii	\"@(\"\"#)" #prefix ": \""		\
	"\n	.asciz	\"" string "\""				\
	"\n	.previous")
#else
#define __IDSTRING(prefix,string)				\
	static const char __IDSTRING_EXPAND(__LINE__,prefix) []	\
	    MKSH_A_USED = "@(""#)" #prefix ": " string
#endif
#define __COPYRIGHT(x)		__IDSTRING(copyright,x)
#define __RCSID(x)		__IDSTRING(rcsid,x)
#define __SCCSID(x)		__IDSTRING(sccsid,x)
#endif

#ifdef EXTERN
__RCSID("$MirOS: src/bin/mksh/sh.h,v 1.898 2020/05/16 22:38:23 tg Exp $");
#endif
#define MKSH_VERSION "R59 2020/05/16"

/* arithmetic types: C implementation */
#if !HAVE_CAN_INTTYPES
#if !HAVE_CAN_UCBINTS
typedef signed int int32_t;
typedef unsigned int uint32_t;
#else
typedef u_int32_t uint32_t;
#endif
#endif

/* arithmetic types: shell arithmetics */
#ifdef MKSH_LEGACY_MODE
/*
 * POSIX demands these to be the C environment's long type
 */
typedef long mksh_ari_t;
typedef unsigned long mksh_uari_t;
#else
/*
 * These types are exactly 32 bit wide; signed and unsigned
 * integer wraparound, even across division and modulo, for
 * any shell code using them, is guaranteed.
 */
typedef int32_t mksh_ari_t;
typedef uint32_t mksh_uari_t;
#endif

/* boolean type (no <stdbool.h> deliberately) */
typedef unsigned char mksh_bool;
#undef bool
/* false MUST equal the same 0 as written by static storage initialisation */
#undef false
#undef true
/* access macros for boolean type */
#define bool		mksh_bool
/* values must have identity mapping between mksh_bool and short */
#define false		0
#define true		1
/* make any-type into bool or short */
#define tobool(cond)	((cond) ? true : false)

/* char (octet) type: C implementation */
#if !HAVE_CAN_INT8TYPE
#if !HAVE_CAN_UCBINT8
typedef unsigned char uint8_t;
#else
typedef u_int8_t uint8_t;
#endif
#endif

/* other standard types */

#if !HAVE_RLIM_T
typedef unsigned long rlim_t;
#endif

#if !HAVE_SIG_T
#undef sig_t
typedef void (*sig_t)(int);
#endif

#ifdef MKSH_TYPEDEF_SIG_ATOMIC_T
typedef MKSH_TYPEDEF_SIG_ATOMIC_T sig_atomic_t;
#endif

#ifdef MKSH_TYPEDEF_SSIZE_T
typedef MKSH_TYPEDEF_SSIZE_T ssize_t;
#endif

#if defined(MKSH_SMALL) && !defined(MKSH_SMALL_BUT_FAST)
#define MKSH_SHF_NO_INLINE
#endif

/* do not merge these conditionals as neatcc’s preprocessor is simple */
#ifdef __neatcc__
/* parsing of comma operator <,> in expressions broken */
#define MKSH_SHF_NO_INLINE
#endif

/* un-do vendor damage */

#undef BAD		/* AIX defines that somewhere */
#undef PRINT		/* LynxOS defines that somewhere */
#undef flock		/* SCO UnixWare defines that to flock64 but ENOENT */


#ifndef MKSH_INCLUDES_ONLY

/* compile-time assertions */
#define cta(name,expr)	struct cta_ ## name { char t[(expr) ? 1 : -1]; }

/* EBCDIC fun */

/* see the large comment in shf.c for an EBCDIC primer */

#if defined(MKSH_FOR_Z_OS) && defined(__MVS__) && defined(__IBMC__) && defined(__CHARSET_LIB)
# if !__CHARSET_LIB && !defined(MKSH_EBCDIC)
#  error "Please compile with Build.sh -E for EBCDIC!"
# endif
# if __CHARSET_LIB && defined(MKSH_EBCDIC)
#  error "Please compile without -E argument to Build.sh for ASCII!"
# endif
# if __CHARSET_LIB && !defined(_ENHANCED_ASCII_EXT)
   /* go all-out on ASCII */
#  define _ENHANCED_ASCII_EXT 0xFFFFFFFF
# endif
#endif

/* extra types */

/* getrusage does not exist on OS/2 kLIBC */
#if !HAVE_GETRUSAGE && !defined(__OS2__)
#undef rusage
#undef RUSAGE_SELF
#undef RUSAGE_CHILDREN
#define rusage mksh_rusage
#define RUSAGE_SELF		0
#define RUSAGE_CHILDREN		-1

struct rusage {
	struct timeval ru_utime;
	struct timeval ru_stime;
};
#endif

/* extra macros */

#ifndef timerclear
#define timerclear(tvp)							\
	do {								\
		(tvp)->tv_sec = (tvp)->tv_usec = 0;			\
	} while (/* CONSTCOND */ 0)
#endif
#ifndef timeradd
#define timeradd(tvp,uvp,vvp)						\
	do {								\
		(vvp)->tv_sec = (tvp)->tv_sec + (uvp)->tv_sec;		\
		(vvp)->tv_usec = (tvp)->tv_usec + (uvp)->tv_usec;	\
		if ((vvp)->tv_usec >= 1000000) {			\
			(vvp)->tv_sec++;				\
			(vvp)->tv_usec -= 1000000;			\
		}							\
	} while (/* CONSTCOND */ 0)
#endif
#ifndef timersub
#define timersub(tvp,uvp,vvp)						\
	do {								\
		(vvp)->tv_sec = (tvp)->tv_sec - (uvp)->tv_sec;		\
		(vvp)->tv_usec = (tvp)->tv_usec - (uvp)->tv_usec;	\
		if ((vvp)->tv_usec < 0) {				\
			(vvp)->tv_sec--;				\
			(vvp)->tv_usec += 1000000;			\
		}							\
	} while (/* CONSTCOND */ 0)
#endif

#ifdef MKSH__NO_PATH_MAX
#undef PATH_MAX
#else
#ifndef PATH_MAX
#ifdef MAXPATHLEN
#define PATH_MAX	MAXPATHLEN
#else
#define PATH_MAX	1024
#endif
#endif
#endif
#ifndef SIZE_MAX
#ifdef SIZE_T_MAX
#define SIZE_MAX	SIZE_T_MAX
#else
#define SIZE_MAX	((size_t)-1)
#endif
#endif
#ifndef S_ISLNK
#define S_ISLNK(m)	((m & 0170000) == 0120000)
#endif
#ifndef S_ISSOCK
#define S_ISSOCK(m)	((m & 0170000) == 0140000)
#endif
#if !defined(S_ISCDF) && defined(S_CDF)
#define S_ISCDF(m)	(S_ISDIR(m) && ((m) & S_CDF))
#endif
#ifndef DEFFILEMODE
#define DEFFILEMODE	(S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
#endif


/* determine ksh_NSIG: first, use the traditional definitions */
#undef ksh_NSIG
#if defined(NSIG)
#define ksh_NSIG (NSIG)
#elif defined(_NSIG)
#define ksh_NSIG (_NSIG)
#elif defined(SIGMAX)
#define ksh_NSIG (SIGMAX + 1)
#elif defined(_SIGMAX)
#define ksh_NSIG (_SIGMAX + 1)
#elif defined(NSIG_MAX)
#define ksh_NSIG (NSIG_MAX)
#elif defined(MKSH_FOR_Z_OS)
#define ksh_NSIG 40
#else
# error Please have your platform define NSIG.
#endif
/* range-check them */
#if (ksh_NSIG < 1)
# error Your NSIG value is not positive.
#undef ksh_NSIG
#endif
/* second, see if the new POSIX definition is available */
#ifdef NSIG_MAX
#if (NSIG_MAX < 2)
/* and usable */
# error Your NSIG_MAX value is too small.
#undef NSIG_MAX
#elif (ksh_NSIG > NSIG_MAX)
/* and realistic */
# error Your NSIG value is larger than your NSIG_MAX value.
#undef NSIG_MAX
#else
/* since it’s usable, prefer it */
#undef ksh_NSIG
#define ksh_NSIG (NSIG_MAX)
#endif
/* if NSIG_MAX is now still defined, use sysconf(_SC_NSIG) at runtime */
#endif
/* third, for cpp without the error directive, default */
#ifndef ksh_NSIG
#define ksh_NSIG 64
#endif

#define ksh_sigmask(sig) (((sig) < 1 || (sig) > 127) ? 255 : 128 + (sig))


/* OS-dependent additions (functions, variables, by OS) */

#ifdef MKSH_EXE_EXT
#undef MKSH_EXE_EXT
#define MKSH_EXE_EXT	".exe"
#else
#define MKSH_EXE_EXT	""
#endif

#ifdef __OS2__
#define MKSH_UNIXROOT	"/@unixroot"
#else
#define MKSH_UNIXROOT	""
#endif

#ifdef MKSH_DOSPATH
#ifndef __GNUC__
# error GCC extensions needed later on
#endif
#define MKSH_PATHSEPS	";"
#define MKSH_PATHSEPC	';'
#else
#define MKSH_PATHSEPS	":"
#define MKSH_PATHSEPC	':'
#endif

#if !HAVE_FLOCK_DECL
extern int flock(int, int);
#endif

#if !HAVE_GETTIMEOFDAY
#define mksh_TIME(tv) do {		\
	(tv).tv_usec = 0;		\
	(tv).tv_sec = time(NULL);	\
} while (/* CONSTCOND */ 0)
#else
#define mksh_TIME(tv) gettimeofday(&(tv), NULL)
#endif

#if !HAVE_GETRUSAGE
extern int getrusage(int, struct rusage *);
#endif

#if !HAVE_MEMMOVE
/* we assume either memmove or bcopy exist, at the moment */
#define memmove(dst,src,len)	bcopy((src), (dst), (len))
#endif

#if !HAVE_REVOKE_DECL
extern int revoke(const char *);
#endif

#if defined(DEBUG) || !HAVE_STRERROR
#undef strerror
#define strerror		/* poisoned */ dontuse_strerror
#define cstrerror		/* replaced */ cstrerror
extern const char *cstrerror(int);
#else
#define cstrerror(errnum)	((const char *)strerror(errnum))
#endif

#if !HAVE_STRLCPY
size_t strlcpy(char *, const char *, size_t);
#endif

#ifdef __INTERIX
/* XXX imake style */
#define makedev mkdev
extern int __cdecl seteuid(uid_t);
extern int __cdecl setegid(gid_t);
#endif

#if defined(__COHERENT__)
#ifndef O_ACCMODE
/* this need not work everywhere, take care */
#define O_ACCMODE	(O_RDONLY | O_WRONLY | O_RDWR)
#endif
#endif

#ifndef O_BINARY
#define O_BINARY	0
#endif

#undef O_MAYEXEC	/* https://lwn.net/Articles/820658/ */
#define O_MAYEXEC	0

#ifdef MKSH__NO_SYMLINK
#undef S_ISLNK
#define S_ISLNK(m)	(/* CONSTCOND */ 0)
#define mksh_lstat	stat
#else
#define mksh_lstat	lstat
#endif

#if HAVE_TERMIOS_H
#define mksh_ttyst	struct termios
#define mksh_tcget(fd,st) tcgetattr((fd), (st))
#define mksh_tcset(fd,st) tcsetattr((fd), TCSADRAIN, (st))
#else
#define mksh_ttyst	struct termio
#define mksh_tcget(fd,st) ioctl((fd), TCGETA, (st))
#define mksh_tcset(fd,st) ioctl((fd), TCSETAW, (st))
#endif

#ifndef ISTRIP
#define ISTRIP		0
#endif

#ifdef MKSH_EBCDIC
#define KSH_BEL		'\a'
#define KSH_ESC		047
#define KSH_ESC_STRING	"\047"
#define KSH_VTAB	'\v'
#else
/*
 * According to the comments in pdksh, \007 seems to be more portable
 * than \a (HP-UX cc, Ultrix cc, old pcc, etc.) so we avoid the escape
 * sequence if ASCII can be assumed.
 */
#define KSH_BEL		7
#define KSH_ESC		033
#define KSH_ESC_STRING	"\033"
#define KSH_VTAB	11
#endif


/* some useful #defines */
#ifdef EXTERN
# define E_INIT(i) = i
#else
# define E_INIT(i)
# define EXTERN extern
# define EXTERN_DEFINED
#endif

/* define bit in flag */
#define BIT(i)		(1U << (i))
#define NELEM(a)	(sizeof(a) / sizeof((a)[0]))

/*
 * Make MAGIC a char that might be printed to make bugs more obvious, but
 * not a char that is used often. Also, can't use the high bit as it causes
 * portability problems (calling strchr(x, 0x80 | 'x') is error prone).
 *
 * MAGIC can be followed by MAGIC (to escape the octet itself) or one of:
 * ' !)*,-?[]{|}' 0x80|' !*+?@' (probably… hysteric raisins abound)
 *
 * The |0x80 is likely unsafe on EBCDIC :( though the listed chars are
 * low-bit7 at least on cp1047 so YMMV
 */
#define MAGIC		KSH_BEL	/* prefix for *?[!{,} during expand */
#define ISMAGIC(c)	(ord(c) == ORD(MAGIC))

EXTERN const char *safe_prompt; /* safe prompt if PS1 substitution fails */

#ifdef MKSH_LEGACY_MODE
#define KSH_VERSIONNAME_ISLEGACY	"LEGACY"
#else
#define KSH_VERSIONNAME_ISLEGACY	"MIRBSD"
#endif
#ifdef MKSH_WITH_TEXTMODE
#define KSH_VERSIONNAME_TEXTMODE	" +TEXTMODE"
#else
#define KSH_VERSIONNAME_TEXTMODE	""
#endif
#ifdef MKSH_EBCDIC
#define KSH_VERSIONNAME_EBCDIC		" +EBCDIC"
#else
#define KSH_VERSIONNAME_EBCDIC		""
#endif
#ifndef KSH_VERSIONNAME_VENDOR_EXT
#define KSH_VERSIONNAME_VENDOR_EXT	""
#endif
EXTERN const char initvsn[] E_INIT("KSH_VERSION=@(#)" KSH_VERSIONNAME_ISLEGACY \
    " KSH " MKSH_VERSION KSH_VERSIONNAME_EBCDIC KSH_VERSIONNAME_TEXTMODE \
    KSH_VERSIONNAME_VENDOR_EXT);
#define KSH_VERSION	(initvsn + /* "KSH_VERSION=@(#)" */ 16)

EXTERN const char digits_uc[] E_INIT("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
EXTERN const char digits_lc[] E_INIT("0123456789abcdefghijklmnopqrstuvwxyz");

/*
 * Evil hack for const correctness due to API brokenness
 */
union mksh_cchack {
	char *rw;
	const char *ro;
};
union mksh_ccphack {
	char **rw;
	const char **ro;
};

/*
 * Evil hack since casting uint to sint is implementation-defined
 */
typedef union {
	mksh_ari_t i;
	mksh_uari_t u;
} mksh_ari_u;

/* for const debugging */
#if defined(DEBUG) && defined(__GNUC__) && !defined(__ICC) && \
    !defined(__INTEL_COMPILER) && !defined(__SUNPRO_C)
char *ucstrchr(char *, int);
char *ucstrstr(char *, const char *);
#undef strchr
#define strchr ucstrchr
#define strstr ucstrstr
#define cstrchr(s,c) ({			\
	union mksh_cchack in, out;	\
					\
	in.ro = (s);			\
	out.rw = ucstrchr(in.rw, (c));	\
	(out.ro);			\
})
#define cstrstr(b,l) ({			\
	union mksh_cchack in, out;	\
					\
	in.ro = (b);			\
	out.rw = ucstrstr(in.rw, (l));	\
	(out.ro);			\
})
#define vstrchr(s,c)	(cstrchr((s), (c)) != NULL)
#define vstrstr(b,l)	(cstrstr((b), (l)) != NULL)
#else /* !DEBUG, !gcc */
#define cstrchr(s,c)	((const char *)strchr((s), (c)))
#define cstrstr(s,c)	((const char *)strstr((s), (c)))
#define vstrchr(s,c)	(strchr((s), (c)) != NULL)
#define vstrstr(b,l)	(strstr((b), (l)) != NULL)
#endif

#if defined(DEBUG) || defined(__COVERITY__)
#ifndef DEBUG_LEAKS
#define DEBUG_LEAKS
#endif
#endif

#if (!defined(MKSH_BUILDMAKEFILE4BSD) && !defined(MKSH_BUILDSH)) || (MKSH_BUILD_R != 592)
#error Must run Build.sh to compile this.
extern void thiswillneverbedefinedIhope(void);
int
im_sorry_dave(void)
{
	/* I’m sorry, Dave. I’m afraid I can’t do that. */
	return (thiswillneverbedefinedIhope());
}
#endif

/* use this ipv strchr(s, 0) but no side effects in s! */
#define strnul(s)	((s) + strlen((const void *)s))

#define utf_ptradjx(src,dst) do {					\
	(dst) = (src) + utf_ptradj(src);				\
} while (/* CONSTCOND */ 0)

#if defined(MKSH_SMALL) && !defined(MKSH_SMALL_BUT_FAST)
#define strdupx(d,s,ap) do {						\
	(d) = strdup_i((s), (ap));					\
} while (/* CONSTCOND */ 0)
#define strndupx(d,s,n,ap) do {						\
	(d) = strndup_i((s), (n), (ap));				\
} while (/* CONSTCOND */ 0)
#else
/* be careful to evaluate arguments only once! */
#define strdupx(d,s,ap) do {						\
	const char *strdup_src = (const void *)(s);			\
	char *strdup_dst = NULL;					\
									\
	if (strdup_src != NULL) {					\
		size_t strdup_len = strlen(strdup_src) + 1;		\
		strdup_dst = alloc(strdup_len, (ap));			\
		memcpy(strdup_dst, strdup_src, strdup_len);		\
	}								\
	(d) = strdup_dst;						\
} while (/* CONSTCOND */ 0)
#define strndupx(d,s,n,ap) do {						\
	const char *strdup_src = (const void *)(s);			\
	char *strdup_dst = NULL;					\
									\
	if (strdup_src != NULL) {					\
		size_t strndup_len = (n);				\
		strdup_dst = alloc(strndup_len + 1, (ap));		\
		memcpy(strdup_dst, strdup_src, strndup_len);		\
		strdup_dst[strndup_len] = '\0';				\
	}								\
	(d) = strdup_dst;						\
} while (/* CONSTCOND */ 0)
#endif
#define strdup2x(d,s1,s2) do {						\
	const char *strdup_src = (const void *)(s1);			\
	const char *strdup_app = (const void *)(s2);			\
	size_t strndup_len = strlen(strdup_src);			\
	size_t strndup_ln2 = strlen(strdup_app) + 1;			\
	char *strdup_dst = alloc(strndup_len + strndup_ln2, ATEMP);	\
									\
	memcpy(strdup_dst, strdup_src, strndup_len);			\
	memcpy(strdup_dst + strndup_len, strdup_app, strndup_ln2);	\
	(d) = strdup_dst;						\
} while (/* CONSTCOND */ 0)
#define strpathx(d,s1,s2,cond) do {					\
	const char *strdup_src = (const void *)(s1);			\
	const char *strdup_app = (const void *)(s2);			\
	size_t strndup_len = strlen(strdup_src) + 1;			\
	size_t strndup_ln2 = ((cond) || *strdup_app) ?			\
	    strlen(strdup_app) + 1 : 0;					\
	char *strdup_dst = alloc(strndup_len + strndup_ln2, ATEMP);	\
									\
	memcpy(strdup_dst, strdup_src, strndup_len);			\
	if (strndup_ln2) {						\
		strdup_dst[strndup_len - 1] = '/';			\
		memcpy(strdup_dst + strndup_len, strdup_app,		\
		    strndup_ln2);					\
	}								\
	(d) = strdup_dst;						\
} while (/* CONSTCOND */ 0)

#ifdef MKSH_SMALL
#ifndef MKSH_NOPWNAM
#define MKSH_NOPWNAM		/* defined */
#endif
#ifndef MKSH_S_NOVI
#define MKSH_S_NOVI		1
#endif
#endif

#ifndef MKSH_S_NOVI
#define MKSH_S_NOVI		0
#endif

#if defined(MKSH_NOPROSPECTOFWORK) && !defined(MKSH_UNEMPLOYED)
#define MKSH_UNEMPLOYED		1
#endif

#define NUFILE		32	/* Number of user-accessible files */
#define FDBASE		10	/* First file usable by Shell */

/*
 * simple grouping allocator
 */


/* 0. OS API: where to get memory from and how to free it (grouped) */

/* malloc(3)/realloc(3) -> free(3) for use by the memory allocator */
#define malloc_osi(sz)		malloc(sz)
#define realloc_osi(p,sz)	realloc((p), (sz))
#define free_osimalloc(p)	free(p)

/* malloc(3)/realloc(3) -> free(3) for use by mksh code */
#define malloc_osfunc(sz)	malloc(sz)
#define realloc_osfunc(p,sz)	realloc((p), (sz))
#define free_osfunc(p)		free(p)

#if HAVE_MKNOD
/* setmode(3) -> free(3) */
#define free_ossetmode(p)	free(p)
#endif

#ifdef MKSH__NO_PATH_MAX
/* GNU libc: get_current_dir_name(3) -> free(3) */
#define free_gnu_gcdn(p)	free(p)
#endif


/* 1. internal structure */
struct lalloc_common {
	struct lalloc_common *next;
};

#ifdef MKSH_ALLOC_CATCH_UNDERRUNS
struct lalloc_item {
	struct lalloc_common *next;
	size_t len;
	char dummy[8192 - sizeof(struct lalloc_common *) - sizeof(size_t)];
};
#endif

/* 2. sizes */
#ifdef MKSH_ALLOC_CATCH_UNDERRUNS
#define ALLOC_ITEM	struct lalloc_item
#define ALLOC_OVERHEAD	0
#else
#define ALLOC_ITEM	struct lalloc_common
#define ALLOC_OVERHEAD	(sizeof(ALLOC_ITEM))
#endif

/* 3. group structure */
typedef struct lalloc_common Area;


EXTERN Area aperm;		/* permanent object space */
#define APERM	&aperm
#define ATEMP	&e->area

/*
 * flags (the order of these enums MUST match the order in misc.c(options[]))
 */
enum sh_flag {
#define SHFLAGS_ENUMS
#include "sh_flags.gen"
	FNFLAGS		/* (place holder: how many flags are there) */
};

#define Flag(f)	(shell_flags[(int)(f)])
#define UTFMODE	Flag(FUNNYCODE)

/*
 * parsing & execution environment
 *
 * note that kshlongjmp MUST NOT be passed 0 as second argument!
 */
#ifdef MKSH_NO_SIGSETJMP
#define kshjmp_buf	jmp_buf
#define kshsetjmp(jbuf)	_setjmp(jbuf)
#define kshlongjmp	_longjmp
#else
#define kshjmp_buf	sigjmp_buf
#define kshsetjmp(jbuf)	sigsetjmp((jbuf), 0)
#define kshlongjmp	siglongjmp
#endif

struct sretrace_info;
struct yyrecursive_state;

EXTERN struct sretrace_info *retrace_info;
EXTERN unsigned int subshell_nesting_type;

extern struct env {
	ALLOC_ITEM alloc_INT;	/* internal, do not touch */
	Area area;		/* temporary allocation area */
	struct env *oenv;	/* link to previous environment */
	struct block *loc;	/* local variables and functions */
	short *savefd;		/* original redirected fds */
	struct temp *temps;	/* temp files */
	/* saved parser recursion state */
	struct yyrecursive_state *yyrecursive_statep;
	kshjmp_buf jbuf;	/* long jump back to env creator */
	uint8_t type;		/* environment type - see below */
	uint8_t flags;		/* EF_* */
} *e;

/* struct env.type values */
#define E_NONE	0	/* dummy environment */
#define E_PARSE	1	/* parsing command # */
#define E_FUNC	2	/* executing function # */
#define E_INCL	3	/* including a file via . # */
#define E_EXEC	4	/* executing command tree */
#define E_LOOP	5	/* executing for/while # */
#define E_ERRH	6	/* general error handler # */
#define E_GONE	7	/* hidden in child */
#define E_EVAL	8	/* running eval # */
/* # indicates env has valid jbuf (see unwind()) */

/* struct env.flag values */
#define EF_BRKCONT_PASS	BIT(1)	/* set if E_LOOP must pass break/continue on */
#define EF_FAKE_SIGDIE	BIT(2)	/* hack to get info from unwind to quitenv */
#define EF_IN_EVAL	BIT(3)	/* inside an eval */

/* Do breaks/continues stop at env type e? */
#define STOP_BRKCONT(t)	((t) == E_NONE || (t) == E_PARSE || \
			    (t) == E_FUNC || (t) == E_INCL)
/* Do returns stop at env type e? */
#define STOP_RETURN(t)	((t) == E_FUNC || (t) == E_INCL)

/* values for kshlongjmp(e->jbuf, i) */
/* note that i MUST NOT be zero */
#define LRETURN	1	/* return statement */
#define LEXIT	2	/* exit statement */
#define LERROR	3	/* errorf() called */
#define LERREXT 4	/* set -e caused */
#define LINTR	5	/* ^C noticed */
#define LBREAK	6	/* break statement */
#define LCONTIN	7	/* continue statement */
#define LSHELL	8	/* return to interactive shell() */
#define LAEXPR	9	/* error in arithmetic expression */
#define LLEAVE	10	/* untrappable exit/error */

/* sort of shell global state */
EXTERN pid_t procpid;		/* PID of executing process */
EXTERN int exstat;		/* exit status */
EXTERN int subst_exstat;	/* exit status of last $(..)/`..` */
EXTERN struct tbl *vp_pipest;	/* global PIPESTATUS array */
EXTERN short trap_exstat;	/* exit status before running a trap */
EXTERN uint8_t trap_nested;	/* running nested traps */
EXTERN uint8_t shell_flags[FNFLAGS];
EXTERN uint8_t baseline_flags[FNFLAGS
#if !defined(MKSH_SMALL) || defined(DEBUG)
    + 1
#endif
    ];
EXTERN bool as_builtin;		/* direct builtin call */
EXTERN const char *kshname;	/* $0 */
EXTERN struct {
	uid_t kshuid_v;		/* real UID of shell at startup */
	uid_t ksheuid_v;	/* effective UID of shell */
	gid_t kshgid_v;		/* real GID of shell at startup */
	gid_t kshegid_v;	/* effective GID of shell */
	pid_t kshpgrp_v;	/* process group of shell */
	pid_t kshppid_v;	/* PID of parent of shell */
	pid_t kshpid_v;		/* $$, shell PID */
} rndsetupstate;

#define kshpid		rndsetupstate.kshpid_v
#define kshpgrp		rndsetupstate.kshpgrp_v
#define kshuid		rndsetupstate.kshuid_v
#define ksheuid		rndsetupstate.ksheuid_v
#define kshgid		rndsetupstate.kshgid_v
#define kshegid		rndsetupstate.kshegid_v
#define kshppid		rndsetupstate.kshppid_v


/* option processing */
#define OF_CMDLINE	0x01	/* command line */
#define OF_SET		0x02	/* set builtin */
#define OF_SPECIAL	0x04	/* a special variable changing */
#define OF_INTERNAL	0x08	/* set internally by shell */
#define OF_FIRSTTIME	0x10	/* as early as possible, once */
#define OF_ANY		(OF_CMDLINE | OF_SET | OF_SPECIAL | OF_INTERNAL)

/* null value for variable; comparison pointer for unset */
EXTERN char null[] E_INIT("");

/* string pooling: do we rely on the compiler? */
#ifndef HAVE_STRING_POOLING
/* no, we use our own, saves quite some space */
#elif HAVE_STRING_POOLING == 2
/* “on demand” */
#ifdef __GNUC__
/* only for GCC 4 or later, older ones can get by without */
#if __GNUC__ < 4
#undef HAVE_STRING_POOLING
#endif
#else
/* not GCC, default to on */
#endif
#elif HAVE_STRING_POOLING == 0
/* default to on, unless explicitly set to 0 */
#undef HAVE_STRING_POOLING
#endif

#ifndef HAVE_STRING_POOLING /* helpers for pooled strings */
EXTERN const char T4spaces[] E_INIT("    ");
#define T1space (Treal_sp2 + 5)
#define Tcolsp (Tf_sD_ + 2)
#define TC_IFSWS (TinitIFS + 4)
EXTERN const char TinitIFS[] E_INIT("IFS= \t\n");
EXTERN const char TFCEDIT_dollaru[] E_INIT("${FCEDIT:-/bin/ed} $_");
#define Tspdollaru (TFCEDIT_dollaru + 18)
EXTERN const char Tsgdot[] E_INIT("*=.");
EXTERN const char Taugo[] E_INIT("augo");
EXTERN const char Tbracket[] E_INIT("[");
#define Tdot (Tsgdot + 2)
#define Talias (Tunalias + 2)
EXTERN const char Tbadnum[] E_INIT("bad number");
#define Tbadsubst (Tfg_badsubst + 10)
EXTERN const char Tbg[] E_INIT("bg");
EXTERN const char Tbad_bsize[] E_INIT("bad shf/buf/bsize");
#define Tbsize (Tbad_bsize + 12)
EXTERN const char Tbad_sig_ss[] E_INIT("%s: bad signal '%s'");
#define Tbad_sig_s (Tbad_sig_ss + 4)
EXTERN const char Tsgbreak[] E_INIT("*=break");
#define Tbreak (Tsgbreak + 2)
EXTERN const char T__builtin[] E_INIT("-\\builtin");
#define T_builtin (T__builtin + 1)
#define Tbuiltin (T__builtin + 2)
EXTERN const char Toomem[] E_INIT("can't allocate %zu data bytes");
EXTERN const char Tcant_cd[] E_INIT("restricted shell - can't cd");
EXTERN const char Tcant_find[] E_INIT("can't find");
EXTERN const char Tcant_open[] E_INIT("can't open");
#define Tbytes (Toomem + 24)
EXTERN const char Tbcat[] E_INIT("!cat");
#define Tcat (Tbcat + 1)
#define Tcd (Tcant_cd + 25)
#define T_command (T_funny_command + 9)
#define Tcommand (T_funny_command + 10)
EXTERN const char Tsgcontinue[] E_INIT("*=continue");
#define Tcontinue (Tsgcontinue + 2)
EXTERN const char Tcreate[] E_INIT("create");
EXTERN const char TELIF_unexpected[] E_INIT("TELIF unexpected");
EXTERN const char TEXECSHELL[] E_INIT("EXECSHELL");
EXTERN const char TENV[] E_INIT("ENV");
EXTERN const char Tdsgexport[] E_INIT("^*=export");
#define Texport (Tdsgexport + 3)
#ifdef __OS2__
EXTERN const char Textproc[] E_INIT("extproc");
#endif
EXTERN const char Tfalse[] E_INIT("false");
EXTERN const char Tfg[] E_INIT("fg");
EXTERN const char Tfg_badsubst[] E_INIT("fileglob: bad substitution");
#define Tfile (Tfile_fd + 20)
EXTERN const char Tfile_fd[] E_INIT("function definition file");
EXTERN const char TFPATH[] E_INIT("FPATH");
EXTERN const char T_function[] E_INIT(" function");
#define Tfunction (T_function + 1)
EXTERN const char T_funny_command[] E_INIT("funny $()-command");
EXTERN const char Tgetopts[] E_INIT("getopts");
#define Thistory (Tnot_in_history + 7)
EXTERN const char Tintovfl[] E_INIT("integer overflow %zu %c %zu prevented");
EXTERN const char Tinvname[] E_INIT("%s: invalid %s name");
EXTERN const char Tjobs[] E_INIT("jobs");
EXTERN const char Tjob_not_started[] E_INIT("job not started");
EXTERN const char Tmksh[] E_INIT("mksh");
#define Tname (Tinvname + 15)
EXTERN const char Tno_args[] E_INIT("missing argument");
EXTERN const char Tno_OLDPWD[] E_INIT("no OLDPWD");
EXTERN const char Tnot_ident[] E_INIT("is not an identifier");
EXTERN const char Tnot_in_history[] E_INIT("not in history");
EXTERN const char Tnot_found_s[] E_INIT("%s not found");
#define Tnot_found (Tnot_found_s + 3)
#define Tnot_started (Tjob_not_started + 4)
#define TOLDPWD (Tno_OLDPWD + 3)
#define Topen (Tcant_open + 6)
EXTERN const char To_o_reset[] E_INIT(" -o .reset");
#define To_reset (To_o_reset + 4)
#define TPATH (TFPATH + 1)
#define Tpo (Tset_po + 4)
#define Tpv (TpVv + 1)
EXTERN const char TpVv[] E_INIT("Vpv");
#define TPWD (Tno_OLDPWD + 6)
#define Tread (Tshf_read + 4)
EXTERN const char Tdsgreadonly[] E_INIT("^*=readonly");
#define Treadonly (Tdsgreadonly + 3)
EXTERN const char Tredirection_dup[] E_INIT("can't finish (dup) redirection");
#define Tredirection (Tredirection_dup + 19)
#define Treal_sp1 (Treal_sp2 + 1)
EXTERN const char Treal_sp2[] E_INIT(" real ");
EXTERN const char TREPLY[] E_INIT("REPLY");
EXTERN const char Treq_arg[] E_INIT("requires an argument");
EXTERN const char Tselect[] E_INIT("select");
#define Tset (Tf_parm + 18)
EXTERN const char Tset_po[] E_INIT("set +o");
EXTERN const char Tsghset[] E_INIT("*=#set");
#define Tsh (Tmksh + 2)
#define TSHELL (TEXECSHELL + 4)
#define Tshell (Ttoo_many_files + 23)
EXTERN const char Tshf_read[] E_INIT("shf_read");
EXTERN const char Tshf_write[] E_INIT("shf_write");
EXTERN const char Tgsource[] E_INIT("=source");
#define Tsource (Tgsource + 1)
EXTERN const char Tj_suspend[] E_INIT("j_suspend");
#define Tsuspend (Tj_suspend + 2)
EXTERN const char Tsynerr[] E_INIT("syntax error");
EXTERN const char Ttime[] E_INIT("time");
EXTERN const char Ttoo_many_args[] E_INIT("too many arguments");
EXTERN const char Ttoo_many_files[] E_INIT("too many open files in shell");
EXTERN const char Ttrue[] E_INIT("true");
EXTERN const char Ttty_fd_dupof[] E_INIT("dup of tty fd");
#define Ttty_fd (Ttty_fd_dupof + 7)
EXTERN const char Tdgtypeset[] E_INIT("^=typeset");
#define Ttypeset (Tdgtypeset + 2)
#define Tugo (Taugo + 1)
EXTERN const char Tunalias[] E_INIT("unalias");
#define Tunexpected (TELIF_unexpected + 6)
EXTERN const char Tunexpected_type[] E_INIT("%s: unexpected %s type %d");
EXTERN const char Tunknown_option[] E_INIT("unknown option");
EXTERN const char Tunwind[] E_INIT("unwind");
#define Tuser_sp1 (Tuser_sp2 + 1)
EXTERN const char Tuser_sp2[] E_INIT(" user ");
#define Twrite (Tshf_write + 4)
EXTERN const char Tf__S[] E_INIT(" %S");
#define Tf__d (Tunexpected_type + 22)
#define Tf_ss (Tf__ss + 1)
EXTERN const char Tf__ss[] E_INIT(" %s%s");
#define Tf__sN (Tf_s_s_sN + 5)
#define Tf_T (Tf_s_T + 3)
EXTERN const char Tf_dN[] E_INIT("%d\n");
EXTERN const char Tf_s_[] E_INIT("%s ");
EXTERN const char Tf_s_T[] E_INIT("%s %T");
EXTERN const char Tf_s_s_sN[] E_INIT("%s %s %s\n");
#define Tf_s_s (Tf_sD_s_s + 4)
#define Tf__s_s (Tf_sD_s_s + 3)
#define Tf_s_sD_s (Tf_cant_ss_s + 6)
EXTERN const char Tf_optfoo[] E_INIT("%s%s-%c: %s");
EXTERN const char Tf_sD_[] E_INIT("%s: ");
EXTERN const char Tf_szs[] E_INIT("%s: %zd %s");
EXTERN const char Tf_parm[] E_INIT("%s: parameter not set");
EXTERN const char Tf_coproc[] E_INIT("-p: %s");
EXTERN const char Tf_cant_s[] E_INIT("%s: can't %s");
EXTERN const char Tf_cant_ss_s[] E_INIT("can't %s %s: %s");
EXTERN const char Tf_heredoc[] E_INIT("here document '%s' unclosed");
#if HAVE_MKNOD
EXTERN const char Tf_nonnum[] E_INIT("non-numeric %s %s '%s'");
#endif
EXTERN const char Tf_S_[] E_INIT("%S ");
#define Tf_S (Tf__S + 1)
#define Tf_lu (Tf_toolarge + 17)
EXTERN const char Tf_toolarge[] E_INIT("%s %s too large: %lu");
EXTERN const char Tf_ldfailed[] E_INIT("%s %s(%d, %ld) failed: %s");
EXTERN const char Tf_sD_s_sD_s[] E_INIT("%s: %s %s: %s");
EXTERN const char Tf_toomany[] E_INIT("too many %ss");
EXTERN const char Tf_sd[] E_INIT("%s %d");
#define Tf_s (Tf_temp + 28)
EXTERN const char Tft_end[] E_INIT("%;");
EXTERN const char Tft_R[] E_INIT("%R");
#define Tf_d (Tunexpected_type + 23)
EXTERN const char Tf_sD_s_qs[] E_INIT("%s: %s '%s'");
EXTERN const char Tf_ro[] E_INIT("read-only: %s");
EXTERN const char Tf_flags[] E_INIT("%s: flags 0x%X");
EXTERN const char Tf_temp[] E_INIT("can't %s temporary file %s: %s");
EXTERN const char Tf_ssfaileds[] E_INIT("%s: %s failed: %s");
EXTERN const char Tf_sD_sD_s[] E_INIT("%s: %s: %s");
EXTERN const char Tf__c_[] E_INIT("-%c ");
EXTERN const char Tf_sD_s_s[] E_INIT("%s: %s %s");
#define Tf_sN (Tf_s_s_sN + 6)
#define Tf_sD_s (Tf_temp + 24)
EXTERN const char T_devtty[] E_INIT("/dev/tty");
#else /* helpers for string pooling */
#define T4spaces "    "
#define T1space " "
#define Tcolsp ": "
#define TC_IFSWS " \t\n"
#define TinitIFS "IFS= \t\n"
#define TFCEDIT_dollaru "${FCEDIT:-/bin/ed} $_"
#define Tspdollaru " $_"
#define Tsgdot "*=."
#define Taugo "augo"
#define Tbracket "["
#define Tdot "."
#define Talias "alias"
#define Tbadnum "bad number"
#define Tbadsubst "bad substitution"
#define Tbg "bg"
#define Tbad_bsize "bad shf/buf/bsize"
#define Tbsize "bsize"
#define Tbad_sig_ss "%s: bad signal '%s'"
#define Tbad_sig_s "bad signal '%s'"
#define Tsgbreak "*=break"
#define Tbreak "break"
#define T__builtin "-\\builtin"
#define T_builtin "\\builtin"
#define Tbuiltin "builtin"
#define Toomem "can't allocate %zu data bytes"
#define Tcant_cd "restricted shell - can't cd"
#define Tcant_find "can't find"
#define Tcant_open "can't open"
#define Tbytes "bytes"
#define Tbcat "!cat"
#define Tcat "cat"
#define Tcd "cd"
#define T_command "-command"
#define Tcommand "command"
#define Tsgcontinue "*=continue"
#define Tcontinue "continue"
#define Tcreate "create"
#define TELIF_unexpected "TELIF unexpected"
#define TEXECSHELL "EXECSHELL"
#define TENV "ENV"
#define Tdsgexport "^*=export"
#define Texport "export"
#ifdef __OS2__
#define Textproc "extproc"
#endif
#define Tfalse "false"
#define Tfg "fg"
#define Tfg_badsubst "fileglob: bad substitution"
#define Tfile "file"
#define Tfile_fd "function definition file"
#define TFPATH "FPATH"
#define T_function " function"
#define Tfunction "function"
#define T_funny_command "funny $()-command"
#define Tgetopts "getopts"
#define Thistory "history"
#define Tintovfl "integer overflow %zu %c %zu prevented"
#define Tinvname "%s: invalid %s name"
#define Tjobs "jobs"
#define Tjob_not_started "job not started"
#define Tmksh "mksh"
#define Tname "name"
#define Tno_args "missing argument"
#define Tno_OLDPWD "no OLDPWD"
#define Tnot_ident "is not an identifier"
#define Tnot_in_history "not in history"
#define Tnot_found_s "%s not found"
#define Tnot_found "not found"
#define Tnot_started "not started"
#define TOLDPWD "OLDPWD"
#define Topen "open"
#define To_o_reset " -o .reset"
#define To_reset ".reset"
#define TPATH "PATH"
#define Tpo "+o"
#define Tpv "pv"
#define TpVv "Vpv"
#define TPWD "PWD"
#define Tread "read"
#define Tdsgreadonly "^*=readonly"
#define Treadonly "readonly"
#define Tredirection_dup "can't finish (dup) redirection"
#define Tredirection "redirection"
#define Treal_sp1 "real "
#define Treal_sp2 " real "
#define TREPLY "REPLY"
#define Treq_arg "requires an argument"
#define Tselect "select"
#define Tset "set"
#define Tset_po "set +o"
#define Tsghset "*=#set"
#define Tsh "sh"
#define TSHELL "SHELL"
#define Tshell "shell"
#define Tshf_read "shf_read"
#define Tshf_write "shf_write"
#define Tgsource "=source"
#define Tsource "source"
#define Tj_suspend "j_suspend"
#define Tsuspend "suspend"
#define Tsynerr "syntax error"
#define Ttime "time"
#define Ttoo_many_args "too many arguments"
#define Ttoo_many_files "too many open files in shell"
#define Ttrue "true"
#define Ttty_fd_dupof "dup of tty fd"
#define Ttty_fd "tty fd"
#define Tdgtypeset "^=typeset"
#define Ttypeset "typeset"
#define Tugo "ugo"
#define Tunalias "unalias"
#define Tunexpected "unexpected"
#define Tunexpected_type "%s: unexpected %s type %d"
#define Tunknown_option "unknown option"
#define Tunwind "unwind"
#define Tuser_sp1 "user "
#define Tuser_sp2 " user "
#define Twrite "write"
#define Tf__S " %S"
#define Tf__d " %d"
#define Tf_ss "%s%s"
#define Tf__ss " %s%s"
#define Tf__sN " %s\n"
#define Tf_T "%T"
#define Tf_dN "%d\n"
#define Tf_s_ "%s "
#define Tf_s_T "%s %T"
#define Tf_s_s_sN "%s %s %s\n"
#define Tf_s_s "%s %s"
#define Tf__s_s " %s %s"
#define Tf_s_sD_s "%s %s: %s"
#define Tf_optfoo "%s%s-%c: %s"
#define Tf_sD_ "%s: "
#define Tf_szs "%s: %zd %s"
#define Tf_parm "%s: parameter not set"
#define Tf_coproc "-p: %s"
#define Tf_cant_s "%s: can't %s"
#define Tf_cant_ss_s "can't %s %s: %s"
#define Tf_heredoc "here document '%s' unclosed"
#if HAVE_MKNOD
#define Tf_nonnum "non-numeric %s %s '%s'"
#endif
#define Tf_S_ "%S "
#define Tf_S "%S"
#define Tf_lu "%lu"
#define Tf_toolarge "%s %s too large: %lu"
#define Tf_ldfailed "%s %s(%d, %ld) failed: %s"
#define Tf_sD_s_sD_s "%s: %s %s: %s"
#define Tf_toomany "too many %ss"
#define Tf_sd "%s %d"
#define Tf_s "%s"
#define Tft_end "%;"
#define Tft_R "%R"
#define Tf_d "%d"
#define Tf_sD_s_qs "%s: %s '%s'"
#define Tf_ro "read-only: %s"
#define Tf_flags "%s: flags 0x%X"
#define Tf_temp "can't %s temporary file %s: %s"
#define Tf_ssfaileds "%s: %s failed: %s"
#define Tf_sD_sD_s "%s: %s: %s"
#define Tf__c_ "-%c "
#define Tf_sD_s_s "%s: %s %s"
#define Tf_sN "%s\n"
#define Tf_sD_s "%s: %s"
#define T_devtty "/dev/tty"
#endif /* end of string pooling */

typedef uint8_t Temp_type;
/* expanded heredoc */
#define TT_HEREDOC_EXP	0
/* temporary file used for history editing (fc -e) */
#define TT_HIST_EDIT	1
/* temporary file used during in-situ command substitution */
#define TT_FUNSUB	2

/* temp/heredoc files. The file is removed when the struct is freed. */
struct temp {
	struct temp *next;
	struct shf *shf;
	/* pid of process parsed here-doc */
	pid_t pid;
	Temp_type type;
	/* actually longer: name (variable length) */
	char tffn[3];
};

/*
 * stdio and our IO routines
 */

#define shl_xtrace	(&shf_iob[0])	/* for set -x */
#define shl_stdout	(&shf_iob[1])
#define shl_out		(&shf_iob[2])
#ifdef DF
#define shl_dbg		(&shf_iob[3])	/* for DF() */
#endif
EXTERN bool shl_stdout_ok;

/*
 * trap handlers
 */
typedef struct trap {
	const char *name;	/* short name */
	const char *mess;	/* descriptive name */
	char *trap;		/* trap command */
	sig_t cursig;		/* current handler (valid if TF_ORIG_* set) */
	sig_t shtrap;		/* shell signal handler */
	int signal;		/* signal number */
	int flags;		/* TF_* */
	volatile sig_atomic_t set; /* trap pending */
} Trap;

/* values for Trap.flags */
#define TF_SHELL_USES	BIT(0)	/* shell uses signal, user can't change */
#define TF_USER_SET	BIT(1)	/* user has (tried to) set trap */
#define TF_ORIG_IGN	BIT(2)	/* original action was SIG_IGN */
#define TF_ORIG_DFL	BIT(3)	/* original action was SIG_DFL */
#define TF_EXEC_IGN	BIT(4)	/* restore SIG_IGN just before exec */
#define TF_EXEC_DFL	BIT(5)	/* restore SIG_DFL just before exec */
#define TF_DFL_INTR	BIT(6)	/* when received, default action is LINTR */
#define TF_TTY_INTR	BIT(7)	/* tty generated signal (see j_waitj) */
#define TF_CHANGED	BIT(8)	/* used by runtrap() to detect trap changes */
#define TF_FATAL	BIT(9)	/* causes termination if not trapped */

/* values for setsig()/setexecsig() flags argument */
#define SS_RESTORE_MASK	0x3	/* how to restore a signal before an exec() */
#define SS_RESTORE_CURR	0	/* leave current handler in place */
#define SS_RESTORE_ORIG	1	/* restore original handler */
#define SS_RESTORE_DFL	2	/* restore to SIG_DFL */
#define SS_RESTORE_IGN	3	/* restore to SIG_IGN */
#define SS_FORCE	BIT(3)	/* set signal even if original signal ignored */
#define SS_USER		BIT(4)	/* user is doing the set (ie, trap command) */
#define SS_SHTRAP	BIT(5)	/* trap for internal use (ALRM, CHLD, WINCH) */

#define ksh_SIGEXIT 0		/* for trap EXIT */
#define ksh_SIGERR  ksh_NSIG	/* for trap ERR */

EXTERN volatile sig_atomic_t trap;	/* traps pending? */
EXTERN volatile sig_atomic_t intrsig;	/* pending trap interrupts command */
EXTERN volatile sig_atomic_t fatal_trap; /* received a fatal signal */
extern Trap sigtraps[ksh_NSIG + 1];

/* got_winch = 1 when we need to re-adjust the window size */
#ifdef SIGWINCH
EXTERN volatile sig_atomic_t got_winch E_INIT(1);
#else
#define got_winch	true
#endif

/*
 * TMOUT support
 */
/* values for ksh_tmout_state */
enum tmout_enum {
	TMOUT_EXECUTING = 0,	/* executing commands */
	TMOUT_READING,		/* waiting for input */
	TMOUT_LEAVING		/* have timed out */
};
EXTERN unsigned int ksh_tmout;
EXTERN enum tmout_enum ksh_tmout_state;

/* For "You have stopped jobs" message */
EXTERN bool really_exit;

/*
 * fast character classes
 */

/* internal types, do not reference */

/* initially empty — filled at runtime from $IFS */
#define CiIFS	BIT(0)
#define CiCNTRL	BIT(1)	/* \x01‥\x08\x0E‥\x1F\x7F	*/
#define CiUPPER	BIT(2)	/* A‥Z				*/
#define CiLOWER	BIT(3)	/* a‥z				*/
#define CiHEXLT	BIT(4)	/* A‥Fa‥f			*/
#define CiOCTAL	BIT(5)	/* 0‥7				*/
#define CiQCL	BIT(6)	/* &();|			*/
#define CiALIAS	BIT(7)	/* !,.@				*/
#define CiQCX	BIT(8)	/* *[\\				*/
#define CiVAR1	BIT(9)	/* !*@				*/
#define CiQCM	BIT(10)	/* /^~				*/
#define CiDIGIT	BIT(11)	/* 89				*/
#define CiQC	BIT(12)	/* "'				*/
#define CiSPX	BIT(13)	/* \x0B\x0C			*/
#define CiCURLY	BIT(14)	/* {}				*/
#define CiANGLE	BIT(15)	/* <>				*/
#define CiNUL	BIT(16)	/* \x00				*/
#define CiTAB	BIT(17)	/* \x09				*/
#define CiNL	BIT(18)	/* \x0A				*/
#define CiCR	BIT(19)	/* \x0D				*/
#define CiSP	BIT(20)	/* \x20				*/
#define CiHASH	BIT(21)	/* #				*/
#define CiSS	BIT(22)	/* $				*/
#define CiPERCT	BIT(23)	/* %				*/
#define CiPLUS	BIT(24)	/* +				*/
#define CiMINUS	BIT(25)	/* -				*/
#define CiCOLON	BIT(26)	/* :				*/
#define CiEQUAL	BIT(27)	/* =				*/
#define CiQUEST	BIT(28)	/* ?				*/
#define CiBRACK	BIT(29)	/* []				*/
#define CiUNDER	BIT(30)	/* _				*/
#define CiGRAVE	BIT(31)	/* `				*/
/* out of space, but one for *@ would make sense, possibly others */

/* compile-time initialised, ASCII only */
extern const uint32_t tpl_ctypes[128];
/* run-time, contains C_IFS as well, full 2⁸ octet range */
EXTERN uint32_t ksh_ctypes[256];
/* first octet of $IFS, for concatenating "$*" */
EXTERN char ifs0;

/* external types */

/* !%+,-.0‥9:@A‥Z[]_a‥z	valid characters in alias names */
#define C_ALIAS	(CiALIAS | CiBRACK | CiCOLON | CiDIGIT | CiLOWER | CiMINUS | CiOCTAL | CiPERCT | CiPLUS | CiUNDER | CiUPPER)
/* 0‥9A‥Za‥z		alphanumerical */
#define C_ALNUM	(CiDIGIT | CiLOWER | CiOCTAL | CiUPPER)
/* 0‥9A‥Z_a‥z		alphanumerical plus underscore (“word character”) */
#define C_ALNUX	(CiDIGIT | CiLOWER | CiOCTAL | CiUNDER | CiUPPER)
/* A‥Za‥z		alphabetical (upper plus lower) */
#define C_ALPHA	(CiLOWER | CiUPPER)
/* A‥Z_a‥z		alphabetical plus underscore (identifier lead) */
#define C_ALPHX	(CiLOWER | CiUNDER | CiUPPER)
/* \x01‥\x7F		7-bit ASCII except NUL */
#define C_ASCII (CiALIAS | CiANGLE | CiBRACK | CiCNTRL | CiCOLON | CiCR | CiCURLY | CiDIGIT | CiEQUAL | CiGRAVE | CiHASH | CiLOWER | CiMINUS | CiNL | CiOCTAL | CiPERCT | CiPLUS | CiQC | CiQCL | CiQCM | CiQCX | CiQUEST | CiSP | CiSPX | CiSS | CiTAB | CiUNDER | CiUPPER)
/* \x09\x20		tab and space */
#define C_BLANK	(CiSP | CiTAB)
/* \x09\x20"'		separator for completion */
#define C_CFS	(CiQC | CiSP | CiTAB)
/* \x00‥\x1F\x7F	POSIX control characters */
#define C_CNTRL	(CiCNTRL | CiCR | CiNL | CiNUL | CiSPX | CiTAB)
/* 0‥9			decimal digits */
#define C_DIGIT	(CiDIGIT | CiOCTAL)
/* &();`|			editor x_locate_word() command */
#define C_EDCMD	(CiGRAVE | CiQCL)
/* \x09\x0A\x20"&'():;<=>`|	editor non-word characters */
#define C_EDNWC	(CiANGLE | CiCOLON | CiEQUAL | CiGRAVE | CiNL | CiQC | CiQCL | CiSP | CiTAB)
/* "#$&'()*:;<=>?[\\`{|}	editor quotes for tab completion */
#define C_EDQ	(CiANGLE | CiCOLON | CiCURLY | CiEQUAL | CiGRAVE | CiHASH | CiQC | CiQCL | CiQCX | CiQUEST | CiSS)
/* !‥~			POSIX graphical (alphanumerical plus punctuation) */
#define C_GRAPH	(C_PUNCT | CiDIGIT | CiLOWER | CiOCTAL | CiUPPER)
/* A‥Fa‥f		hex letter */
#define C_HEXLT	CiHEXLT
/* \x00 + $IFS		IFS whitespace, IFS non-whitespace, NUL */
#define C_IFS	(CiIFS | CiNUL)
/* \x09\x0A\x20		IFS whitespace */
#define C_IFSWS	(CiNL | CiSP | CiTAB)
/* \x09\x0A\x20&();<>|	(for the lexer) */
#define C_LEX1	(CiANGLE | CiNL | CiQCL | CiSP | CiTAB)
/* a‥z			lowercase letters */
#define C_LOWER	CiLOWER
/* not alnux or dollar	separator for motion */
#define C_MFS	(CiALIAS | CiANGLE | CiBRACK | CiCNTRL | CiCOLON | CiCR | CiCURLY | CiEQUAL | CiGRAVE | CiHASH | CiMINUS | CiNL | CiNUL | CiPERCT | CiPLUS | CiQC | CiQCL | CiQCM | CiQCX | CiQUEST | CiSP | CiSPX | CiTAB)
/* 0‥7			octal digit */
#define C_OCTAL	CiOCTAL
/* !*+?@		pattern magical operator, except space */
#define C_PATMO	(CiPLUS | CiQUEST | CiVAR1)
/* \x20‥~		POSIX printable characters (graph plus space) */
#define C_PRINT	(C_GRAPH | CiSP)
/* !"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~	POSIX punctuation */
#define C_PUNCT	(CiALIAS | CiANGLE | CiBRACK | CiCOLON | CiCURLY | CiEQUAL | CiGRAVE | CiHASH | CiMINUS | CiPERCT | CiPLUS | CiQC | CiQCL | CiQCM | CiQCX | CiQUEST | CiSS | CiUNDER)
/* \x09\x0A"#$&'()*;<=>?[\\]`|	characters requiring quoting, minus space */
#define C_QUOTE	(CiANGLE | CiBRACK | CiEQUAL | CiGRAVE | CiHASH | CiNL | CiQC | CiQCL | CiQCX | CiQUEST | CiSS | CiTAB)
/* 0‥9A‥Fa‥f		hexadecimal digit */
#define C_SEDEC	(CiDIGIT | CiHEXLT | CiOCTAL)
/* \x09‥\x0D\x20	POSIX space class */
#define C_SPACE	(CiCR | CiNL | CiSP | CiSPX | CiTAB)
/* +-=?			substitution operations with word */
#define C_SUB1	(CiEQUAL | CiMINUS | CiPLUS | CiQUEST)
/* #%			substitution operations with pattern */
#define C_SUB2	(CiHASH | CiPERCT)
/* A‥Z			uppercase letters */
#define C_UPPER	CiUPPER
/* !#$*-?@		substitution parameters, other than positional */
#define C_VAR1	(CiHASH | CiMINUS | CiQUEST | CiSS | CiVAR1)

/* individual chars you might like */
#define C_ANGLE	CiANGLE		/* <>	angle brackets */
#define C_COLON	CiCOLON		/* :	colon */
#define C_CR	CiCR		/* \x0D	ASCII carriage return */
#define C_DOLAR	CiSS		/* $	dollar sign */
#define C_EQUAL	CiEQUAL		/* =	equals sign */
#define C_GRAVE	CiGRAVE		/* `	accent gravis */
#define C_HASH	CiHASH		/* #	hash sign */
#define C_LF	CiNL		/* \x0A	ASCII line feed */
#define C_MINUS	CiMINUS		/* -	hyphen-minus */
#ifdef MKSH_WITH_TEXTMODE
#define C_NL	(CiNL | CiCR)	/* 	CR or LF under OS/2 TEXTMODE */
#else
#define C_NL	CiNL		/* 	LF only like under Unix */
#endif
#define C_NUL	CiNUL		/* \x00	ASCII NUL */
#define C_PLUS	CiPLUS		/* +	plus sign */
#define C_QC	CiQC		/* "'	quote characters */
#define C_QUEST	CiQUEST		/* ?	question mark */
#define C_SPC	CiSP		/* \x20	ASCII space */
#define C_TAB	CiTAB		/* \x09	ASCII horizontal tabulator */
#define C_UNDER	CiUNDER		/* _	underscore */

/* identity transform of octet */
#if defined(DEBUG) && defined(__GNUC__) && !defined(__ICC) && \
    !defined(__INTEL_COMPILER) && !defined(__SUNPRO_C)
extern unsigned int eek_ord;
#define ORD(c)	((size_t)(c) > 0xFF ? eek_ord : \
		    ((unsigned int)(unsigned char)(c)))
#define ord(c)	__builtin_choose_expr(				\
    __builtin_types_compatible_p(__typeof__(c), char) ||	\
    __builtin_types_compatible_p(__typeof__(c), unsigned char),	\
    ((unsigned int)(unsigned char)(c)), ({			\
	size_t ord_c = (c);					\
								\
	if (ord_c > (size_t)0xFFU)				\
		internal_errorf("%s:%d:ord(%zX)",		\
		    __FILE__, __LINE__, ord_c);			\
	((unsigned int)(unsigned char)(ord_c));			\
}))
#else
#define ord(c)	((unsigned int)(unsigned char)(c))
#define ORD(c)	ord(c) /* may evaluate arguments twice */
#endif
#if defined(MKSH_EBCDIC) || defined(MKSH_FAUX_EBCDIC)
EXTERN unsigned short ebcdic_map[256];
EXTERN unsigned char ebcdic_rtt_toascii[256];
EXTERN unsigned char ebcdic_rtt_fromascii[256];
extern void ebcdic_init(void);
/* one-way to-ascii-or-high conversion, for POSIX locale ordering */
#define asciibetical(c)	((unsigned int)ebcdic_map[(unsigned char)(c)])
/* two-way round-trip conversion, for general use */
#define rtt2asc(c)	ebcdic_rtt_toascii[(unsigned char)(c)]
#define asc2rtt(c)	ebcdic_rtt_fromascii[(unsigned char)(c)]
/* case-independent char comparison */
#define ksh_eq(c,u,l)	(ord(c) == ord(u) || ord(c) == ord(l))
#else
#define asciibetical(c)	ord(c)
#define rtt2asc(c)	((unsigned char)(c))
#define asc2rtt(c)	((unsigned char)(c))
#define ksh_eq(c,u,l)	((ord(c) | 0x20) == ord(l))
#endif
/* control character foo */
#ifdef MKSH_EBCDIC
#define ksh_isctrl(c)	(ord(c) < 0x40 || ord(c) == 0xFF)
#else
#define ksh_isctrl(c)	((ord(c) & 0x7F) < 0x20 || ord(c) == 0x7F)
#endif
/* new fast character classes */
#define ctype(c,t)	tobool(ksh_ctypes[ord(c)] & (t))
#define cinttype(c,t)	((c) >= 0 && (c) <= 0xFF ? \
			tobool(ksh_ctypes[(unsigned char)(c)] & (t)) : false)
/* helper functions */
#define ksh_isdash(s)	tobool(ord((s)[0]) == '-' && ord((s)[1]) == '\0')
/* invariant distance even in EBCDIC */
#define ksh_tolower(c)	(ctype(c, C_UPPER) ? (c) - 'A' + 'a' : (c))
#define ksh_toupper(c)	(ctype(c, C_LOWER) ? (c) - 'a' + 'A' : (c))
/* strictly speaking rtt2asc() here, but this works even in EBCDIC */
#define ksh_numdig(c)	(ord(c) - ORD('0'))
#define ksh_numuc(c)	(rtt2asc(c) - rtt2asc('A'))
#define ksh_numlc(c)	(rtt2asc(c) - rtt2asc('a'))
#define ksh_toctrl(c)	asc2rtt(ord(c) == ORD('?') ? 0x7F : rtt2asc(c) & 0x9F)
#define ksh_unctrl(c)	asc2rtt(rtt2asc(c) ^ 0x40U)

#ifdef MKSH_SMALL
#define SMALLP(x)	/* nothing */
#else
#define SMALLP(x)	, x
#endif

/* Argument parsing for built-in commands and getopts command */

/* Values for Getopt.flags */
#define GF_ERROR	BIT(0)	/* call errorf() if there is an error */
#define GF_PLUSOPT	BIT(1)	/* allow +c as an option */
#define GF_NONAME	BIT(2)	/* don't print argv[0] in errors */

/* Values for Getopt.info */
#define GI_MINUS	BIT(0)	/* an option started with -... */
#define GI_PLUS		BIT(1)	/* an option started with +... */
#define GI_MINUSMINUS	BIT(2)	/* arguments were ended with -- */

/* in case some OS defines these */
#undef optarg
#undef optind

typedef struct {
	const char *optarg;
	int optind;
	int uoptind;		/* what user sees in $OPTIND */
	int flags;		/* see GF_* */
	int info;		/* see GI_* */
	unsigned int p;		/* 0 or index into argv[optind - 1] */
	char buf[2];		/* for bad option OPTARG value */
} Getopt;

EXTERN Getopt builtin_opt;	/* for shell builtin commands */
EXTERN Getopt user_opt;		/* parsing state for getopts builtin command */

/* This for co-processes */

/* something that won't (realisticly) wrap */
typedef int Coproc_id;

struct coproc {
	void *job;	/* 0 or job of co-process using input pipe */
	int read;	/* pipe from co-process's stdout */
	int readw;	/* other side of read (saved temporarily) */
	int write;	/* pipe to co-process's stdin */
	int njobs;	/* number of live jobs using output pipe */
	Coproc_id id;	/* id of current output pipe */
};
EXTERN struct coproc coproc;

#ifndef MKSH_NOPROSPECTOFWORK
/* used in jobs.c and by coprocess stuff in exec.c and select() calls */
EXTERN sigset_t		sm_default, sm_sigchld;
#endif

/* name of called builtin function (used by error functions) */
EXTERN const char *builtin_argv0;
/* is called builtin a POSIX special builtin? (error functions only) */
EXTERN bool builtin_spec;

/* current working directory */
EXTERN char	*current_wd;

/* input line size */
#ifdef MKSH_SMALL
#define LINE		(4096 - ALLOC_OVERHEAD)
#else
#define LINE		(16384 - ALLOC_OVERHEAD)
#endif
/* columns and lines of the tty */
EXTERN mksh_ari_t x_cols E_INIT(80);
EXTERN mksh_ari_t x_lins E_INIT(24);


/* Determine the location of the system (common) profile */

#ifndef MKSH_DEFAULT_PROFILEDIR
#define MKSH_DEFAULT_PROFILEDIR	MKSH_UNIXROOT "/etc"
#endif

#define MKSH_SYSTEM_PROFILE	MKSH_DEFAULT_PROFILEDIR "/profile"
#define MKSH_SUID_PROFILE	MKSH_DEFAULT_PROFILEDIR "/suid_profile"


/* Used by v_evaluate() and setstr() to control action when error occurs */
#define KSH_UNWIND_ERROR	0	/* unwind the stack (kshlongjmp) */
#define KSH_RETURN_ERROR	1	/* return 1/0 for success/failure */

/*
 * Shell file I/O routines
 */

#define SHF_BSIZE		512

#define shf_fileno(shf)		((shf)->fd)
#define shf_setfileno(shf,nfd)	((shf)->fd = (nfd))
#define shf_getc_i(shf)		((shf)->rnleft > 0 ? \
				    (shf)->rnleft--, (int)ord(*(shf)->rp++) : \
				    shf_getchar(shf))
#define shf_putc_i(c,shf)	((shf)->wnleft == 0 ? \
				    shf_putchar((uint8_t)(c), (shf)) : \
				    ((shf)->wnleft--, *(shf)->wp++ = (c)))
#define shf_eof(shf)		((shf)->flags & SHF_EOF)
#define shf_error(shf)		((shf)->flags & SHF_ERROR)
#define shf_errno(shf)		((shf)->errnosv)
#define shf_clearerr(shf)	((shf)->flags &= ~(SHF_EOF | SHF_ERROR))

/* Flags passed to shf_*open() */
#define SHF_RD		0x0001
#define SHF_WR		0x0002
#define SHF_RDWR	(SHF_RD | SHF_WR)
#define SHF_ACCMODE	0x0003		/* mask */
#define SHF_GETFL	0x0004		/* use fcntl() to figure RD/WR flags */
#define SHF_UNBUF	0x0008		/* unbuffered I/O */
#define SHF_CLEXEC	0x0010		/* set close on exec flag */
#define SHF_MAPHI	0x0020		/* make fd > FDBASE (and close orig)
					 * (shf_open() only) */
#define SHF_DYNAMIC	0x0040		/* string: increase buffer as needed */
#define SHF_INTERRUPT	0x0080		/* EINTR in read/write causes error */
/* Flags used internally */
#define SHF_STRING	0x0100		/* a string, not a file */
#define SHF_ALLOCS	0x0200		/* shf and shf->buf were alloc()ed */
#define SHF_ALLOCB	0x0400		/* shf->buf was alloc()ed */
#define SHF_ERROR	0x0800		/* read()/write() error */
#define SHF_EOF		0x1000		/* read eof (sticky) */
#define SHF_READING	0x2000		/* currently reading: rnleft,rp valid */
#define SHF_WRITING	0x4000		/* currently writing: wnleft,wp valid */


struct shf {
	Area *areap;		/* area shf/buf were allocated in */
	unsigned char *rp;	/* read: current position in buffer */
	unsigned char *wp;	/* write: current position in buffer */
	unsigned char *buf;	/* buffer */
	ssize_t bsize;		/* actual size of buf */
	ssize_t rbsize;		/* size of buffer (1 if SHF_UNBUF) */
	ssize_t rnleft;		/* read: how much data left in buffer */
	ssize_t wbsize;		/* size of buffer (0 if SHF_UNBUF) */
	ssize_t wnleft;		/* write: how much space left in buffer */
	int flags;		/* see SHF_* */
	int fd;			/* file descriptor */
	int errnosv;		/* saved value of errno after error */
};

extern struct shf shf_iob[];

struct table {
	Area *areap;		/* area to allocate entries */
	struct tbl **tbls;	/* hashed table items */
	size_t nfree;		/* free table entries */
	uint8_t tshift;		/* table size (2^tshift) */
};

/* table item */
struct tbl {
	/* Area to allocate from */
	Area *areap;
	/* value */
	union {
		char *s;			/* string */
		mksh_ari_t i;			/* integer */
		mksh_uari_t u;			/* unsigned integer */
		int (*f)(const char **);	/* built-in command */
		struct op *t;			/* "function" tree */
	} val;
	union {
		struct tbl *array;	/* array values */
		const char *fpath;	/* temporary path to undef function */
	} u;
	union {
		int field;		/* field with for -L/-R/-Z */
		int errnov;		/* CEXEC/CTALIAS */
	} u2;
	union {
		uint32_t hval;		/* hash(name) */
		uint32_t index;		/* index for an array */
	} ua;
	/*
	 * command type (see below), base (if INTEGER),
	 * offset from val.s of value (if EXPORT)
	 */
	int type;
	/* flags (see below) */
	uint32_t flag;

	/* actually longer: name (variable length) */
	char name[4];
};

EXTERN struct tbl *vtemp;
/* set by isglobal(), global() and local() */
EXTERN bool last_lookup_was_array;

/* common flag bits */
#define ALLOC		BIT(0)	/* val.s has been allocated */
#define DEFINED		BIT(1)	/* is defined in block */
#define ISSET		BIT(2)	/* has value, vp->val.[si] */
#define EXPORT		BIT(3)	/* exported variable/function */
#define TRACE		BIT(4)	/* var: user flagged, func: execution tracing */
/* (start non-common flags at 8) */
/* flag bits used for variables */
#define SPECIAL		BIT(8)	/* PATH, IFS, SECONDS, etc */
#define INTEGER		BIT(9)	/* val.i contains integer value */
#define RDONLY		BIT(10)	/* read-only variable */
#define LOCAL		BIT(11)	/* for local typeset() */
#define ARRAY		BIT(13)	/* array */
#define LJUST		BIT(14)	/* left justify */
#define RJUST		BIT(15)	/* right justify */
#define ZEROFIL		BIT(16)	/* 0 filled if RJUSTIFY, strip 0s if LJUSTIFY */
#define LCASEV		BIT(17)	/* convert to lower case */
#define UCASEV_AL	BIT(18) /* convert to upper case / autoload function */
#define INT_U		BIT(19)	/* unsigned integer */
#define INT_L		BIT(20)	/* long integer (no-op but used as magic) */
#define IMPORT		BIT(21)	/* flag to typeset(): no arrays, must have = */
#define LOCAL_COPY	BIT(22)	/* with LOCAL - copy attrs from existing var */
#define EXPRINEVAL	BIT(23)	/* contents currently being evaluated */
#define EXPRLVALUE	BIT(24)	/* useable as lvalue (temp flag) */
#define AINDEX		BIT(25) /* array index >0 = ua.index filled in */
#define ASSOC		BIT(26) /* ARRAY ? associative : reference */
/* flag bits used for taliases/builtins/aliases/keywords/functions */
#define KEEPASN		BIT(8)	/* keep command assignments (eg, var=x cmd) */
#define FINUSE		BIT(9)	/* function being executed */
#define FDELETE		BIT(10)	/* function deleted while it was executing */
#define FKSH		BIT(11)	/* function defined with function x (vs x()) */
#define SPEC_BI		BIT(12)	/* a POSIX special builtin */
#define LOWER_BI	BIT(13)	/* (with LOW_BI) override even w/o flags */
#define LOW_BI		BIT(14)	/* external utility overrides built-in one */
#define DECL_UTIL	BIT(15)	/* is declaration utility */
#define DECL_FWDR	BIT(16) /* is declaration utility forwarder */
#define NEXTLOC_BI	BIT(17)	/* needs BF_RESETSPEC on e->loc */

/*
 * Attributes that can be set by the user (used to decide if an unset
 * param should be repoted by set/typeset). Does not include ARRAY or
 * LOCAL.
 */
#define USERATTRIB	(EXPORT | INTEGER | RDONLY | LJUST | RJUST | ZEROFIL | \
			    LCASEV | UCASEV_AL | INT_U | INT_L)

#define arrayindex(vp)	((unsigned long)((vp)->flag & AINDEX ? \
			    (vp)->ua.index : 0))

enum namerefflag {
	SRF_NOP,
	SRF_ENABLE,
	SRF_DISABLE
};

/* command types */
#define CNONE		0	/* undefined */
#define CSHELL		1	/* built-in */
#define CFUNC		2	/* function */
#define CEXEC		4	/* executable command */
#define CALIAS		5	/* alias */
#define CKEYWD		6	/* keyword */
#define CTALIAS		7	/* tracked alias */

/* Flags for findcom()/comexec() */
#define FC_SPECBI	BIT(0)	/* special builtin */
#define FC_FUNC		BIT(1)	/* function */
#define FC_NORMBI	BIT(2)	/* not special builtin */
#define FC_BI		(FC_SPECBI | FC_NORMBI)
#define FC_PATH		BIT(3)	/* do path search */
#define FC_DEFPATH	BIT(4)	/* use default path in path search */
#define FC_WHENCE	BIT(5)	/* for use by command and whence */

#define AF_ARGV_ALLOC	0x1	/* argv[] array allocated */
#define AF_ARGS_ALLOCED	0x2	/* argument strings allocated */
#define AI_ARGV(a,i)	((i) == 0 ? (a).argv[0] : (a).argv[(i) - (a).skip])
#define AI_ARGC(a)	((a).ai_argc - (a).skip)

/* Argument info. Used for $#, $* for shell, functions, includes, etc. */
struct arg_info {
	const char **argv;
	int flags;	/* AF_* */
	int ai_argc;
	int skip;	/* first arg is argv[0], second is argv[1 + skip] */
};

/*
 * activation record for function blocks
 */
struct block {
	Area area;		/* area to allocate things */
	const char **argv;
	char *error;		/* error handler */
	char *exit;		/* exit handler */
	struct block *next;	/* enclosing block */
	struct table vars;	/* local variables */
	struct table funs;	/* local functions */
	Getopt getopts_state;
	int argc;
	int flags;		/* see BF_* */
};

/* Values for struct block.flags */
#define BF_DOGETOPTS	BIT(0)	/* save/restore getopts state */
#define BF_STOPENV	BIT(1)	/* do not export further */
/* BF_RESETSPEC and NEXTLOC_BI must be numerically identical! */
#define BF_RESETSPEC	BIT(17)	/* use ->next for set and shift */

/*
 * Used by ktwalk() and ktnext() routines.
 */
struct tstate {
	struct tbl **next;
	ssize_t left;
};

EXTERN struct table taliases;	/* tracked aliases */
EXTERN struct table builtins;	/* built-in commands */
EXTERN struct table aliases;	/* aliases */
EXTERN struct table keywords;	/* keywords */
#ifndef MKSH_NOPWNAM
EXTERN struct table homedirs;	/* homedir() cache */
#endif

struct builtin {
	const char *name;
	int (*func)(const char **);
};

extern const struct builtin mkshbuiltins[];

/* values for set_prompt() */
#define PS1	0	/* command */
#define PS2	1	/* command continuation */

EXTERN char *path;		/* copy of either PATH or def_path */
EXTERN const char *def_path;	/* path to use if PATH not set */
EXTERN char *tmpdir;		/* TMPDIR value */
EXTERN const char *prompt;
EXTERN uint8_t cur_prompt;	/* PS1 or PS2 */
EXTERN int current_lineno;	/* LINENO value */

/*
 * Description of a command or an operation on commands.
 */
struct op {
	const char **args;		/* arguments to a command */
	char **vars;			/* variable assignments */
	struct ioword **ioact;		/* IO actions (eg, < > >>) */
	struct op *left, *right;	/* descendents */
	char *str;			/* word for case; identifier for for,
					 * select, and functions;
					 * path to execute for TEXEC;
					 * time hook for TCOM.
					 */
	int lineno;			/* TCOM/TFUNC: LINENO for this */
	short type;			/* operation type, see below */
	/* WARNING: newtp(), tcopy() use evalflags = 0 to clear union */
	union {
		/* TCOM: arg expansion eval() flags */
		short evalflags;
		/* TFUNC: function x (vs x()) */
		short ksh_func;
		/* TPAT: termination character */
		char charflag;
	} u;
};

/* Tree.type values */
#define TEOF		0
#define TCOM		1	/* command */
#define TPAREN		2	/* (c-list) */
#define TPIPE		3	/* a | b */
#define TLIST		4	/* a ; b */
#define TOR		5	/* || */
#define TAND		6	/* && */
#define TBANG		7	/* ! */
#define TDBRACKET	8	/* [[ .. ]] */
#define TFOR		9
#define TSELECT		10
#define TCASE		11
#define TIF		12
#define TWHILE		13
#define TUNTIL		14
#define TELIF		15
#define TPAT		16	/* pattern in case */
#define TBRACE		17	/* {c-list} */
#define TASYNC		18	/* c & */
#define TFUNCT		19	/* function name { command; } */
#define TTIME		20	/* time pipeline */
#define TEXEC		21	/* fork/exec eval'd TCOM */
#define TCOPROC		22	/* coprocess |& */

/*
 * prefix codes for words in command tree
 */
#define EOS	0	/* end of string */
#define CHAR	1	/* unquoted character */
#define QCHAR	2	/* quoted character */
#define COMSUB	3	/* $() substitution (0 terminated) */
#define EXPRSUB	4	/* $(()) substitution (0 terminated) */
#define OQUOTE	5	/* opening " or ' */
#define CQUOTE	6	/* closing " or ' */
#define OSUBST	7	/* opening ${ subst (followed by { or X) */
#define CSUBST	8	/* closing } of above (followed by } or X) */
#define OPAT	9	/* open pattern: *(, @(, etc. */
#define SPAT	10	/* separate pattern: | */
#define CPAT	11	/* close pattern: ) */
#define ADELIM	12	/* arbitrary delimiter: ${foo:2:3} ${foo/bar/baz} */
#define FUNSUB	14	/* ${ foo;} substitution (NUL terminated) */
#define VALSUB	15	/* ${|foo;} substitution (NUL terminated) */
#define COMASUB	16	/* `…` substitution (COMSUB but expand aliases) */
#define FUNASUB	17	/* function substitution but expand aliases */

/*
 * IO redirection
 */
struct ioword {
	char *ioname;		/* filename (unused if heredoc) */
	char *delim;		/* delimiter for <<, <<- */
	char *heredoc;		/* content of heredoc */
	unsigned short ioflag;	/* action (below) */
	short unit;		/* unit (fd) affected */
};

/* ioword.flag - type of redirection */
#define IOTYPE		0xF	/* type: bits 0:3 */
#define IOREAD		0x1	/* < */
#define IOWRITE		0x2	/* > */
#define IORDWR		0x3	/* <>: todo */
#define IOHERE		0x4	/* << (here file) */
#define IOCAT		0x5	/* >> */
#define IODUP		0x6	/* <&/>& */
#define IOEVAL		BIT(4)	/* expand in << */
#define IOSKIP		BIT(5)	/* <<-, skip ^\t* */
#define IOCLOB		BIT(6)	/* >|, override -o noclobber */
#define IORDUP		BIT(7)	/* x<&y (as opposed to x>&y) */
#define IODUPSELF	BIT(8)	/* x>&x (as opposed to x>&y) */
#define IONAMEXP	BIT(9)	/* name has been expanded */
#define IOBASH		BIT(10)	/* &> etc. */
#define IOHERESTR	BIT(11)	/* <<< (here string) */
#define IONDELIM	BIT(12)	/* null delimiter (<<) */

/* execute/exchild flags */
#define XEXEC	BIT(0)		/* execute without forking */
#define XFORK	BIT(1)		/* fork before executing */
#define XBGND	BIT(2)		/* command & */
#define XPIPEI	BIT(3)		/* input is pipe */
#define XPIPEO	BIT(4)		/* output is pipe */
#define XXCOM	BIT(5)		/* `...` command */
#define XPCLOSE	BIT(6)		/* exchild: close close_fd in parent */
#define XCCLOSE	BIT(7)		/* exchild: close close_fd in child */
#define XERROK	BIT(8)		/* non-zero exit ok (for set -e) */
#define XCOPROC BIT(9)		/* starting a co-process */
#define XTIME	BIT(10)		/* timing TCOM command */
#define XPIPEST	BIT(11)		/* want PIPESTATUS */

/*
 * flags to control expansion of words (assumed by t->evalflags to fit
 * in a short)
 */
#define DOBLANK	BIT(0)		/* perform blank interpretation */
#define DOGLOB	BIT(1)		/* expand [?* */
#define DOPAT	BIT(2)		/* quote *?[ */
#define DOTILDE	BIT(3)		/* normal ~ expansion (first char) */
#define DONTRUNCOMMAND BIT(4)	/* do not run $(command) things */
#define DOASNTILDE BIT(5)	/* assignment ~ expansion (after =, :) */
#define DOBRACE BIT(6)		/* used by expand(): do brace expansion */
#define DOMAGIC BIT(7)		/* used by expand(): string contains MAGIC */
#define DOTEMP	BIT(8)		/* dito: in word part of ${..[%#=?]..} */
#define DOVACHECK BIT(9)	/* var assign check (for typeset, set, etc) */
#define DOMARKDIRS BIT(10)	/* force markdirs behaviour */
#define DOTCOMEXEC BIT(11)	/* not an eval flag, used by sh -c hack */
#define DOSCALAR BIT(12)	/* change field handling to non-list context */
#define DOHEREDOC BIT(13)	/* change scalar handling to heredoc body */
#define DOHERESTR BIT(14)	/* append a newline char */
#define DODBMAGIC BIT(15)	/* add magic to expansions for [[ x = $y ]] */

#define X_EXTRA	20	/* this many extra bytes in X string */
#if defined(MKSH_SMALL) && !defined(MKSH_SMALL_BUT_FAST)
#define X_WASTE 15	/* allowed extra bytes to avoid shrinking, */
#else
#define X_WASTE 255	/* … must be 2ⁿ-1 */
#endif

typedef struct XString {
	/* beginning of string */
	char *beg;
	/* length of allocated area, minus safety margin */
	size_t len;
	/* end of string */
	char *end;
	/* memory area used */
	Area *areap;
} XString;

/* initialise expandable string */
#define XinitN(xs,length,area) do {				\
	(xs).len = (length);					\
	(xs).areap = (area);					\
	(xs).beg = alloc((xs).len + X_EXTRA, (xs).areap);	\
	(xs).end = (xs).beg + (xs).len;				\
} while (/* CONSTCOND */ 0)
#define Xinit(xs,xp,length,area) do {				\
	XinitN((xs), (length), (area));				\
	(xp) = (xs).beg;					\
} while (/* CONSTCOND */ 0)

/* stuff char into string */
#define Xput(xs,xp,c)	(*xp++ = (c))

/* check if there are at least n bytes left */
#define XcheckN(xs,xp,n) do {					\
	ssize_t more = ((xp) + (n)) - (xs).end;			\
	if (more > 0)						\
		(xp) = Xcheck_grow(&(xs), (xp), (size_t)more);	\
} while (/* CONSTCOND */ 0)

/* check for overflow, expand string */
#define Xcheck(xs,xp)	XcheckN((xs), (xp), 1)

/* free string */
#define Xfree(xs,xp)	afree((xs).beg, (xs).areap)

/* close, return string */
#define Xclose(xs,xp)	aresize((xs).beg, (xp) - (xs).beg, (xs).areap)

/* beginning of string */
#define Xstring(xs,xp)	((xs).beg)

#define Xnleft(xs,xp)		((xs).end - (xp))	/* may be less than 0 */
#define Xlength(xs,xp)		((xp) - (xs).beg)
#define Xsize(xs,xp)		((xs).end - (xs).beg)
#define Xsavepos(xs,xp)		((xp) - (xs).beg)
#define Xrestpos(xs,xp,n)	((xs).beg + (n))

char *Xcheck_grow(XString *, const char *, size_t);

/*
 * expandable vector of generic pointers
 */

typedef struct {
	/* beginning of allocated area */
	void **beg;
	/* currently used number of entries */
	size_t len;
	/* allocated number of entries */
	size_t siz;
} XPtrV;

#define XPinit(x,n)	do {					\
	(x).siz = (n);						\
	(x).len = 0;						\
	(x).beg = alloc2((x).siz, sizeof(void *), ATEMP);	\
} while (/* CONSTCOND */ 0)					\

#define XPput(x,p)	do {					\
	if ((x).len == (x).siz) {				\
		(x).beg = aresize2((x).beg, (x).siz,		\
		    2 * sizeof(void *), ATEMP);			\
		(x).siz <<= 1;					\
	}							\
	(x).beg[(x).len++] = (p);				\
} while (/* CONSTCOND */ 0)

#define XPptrv(x)	((x).beg)
#define XPsize(x)	((x).len)
#define XPclose(x)	aresize2((x).beg, XPsize(x), sizeof(void *), ATEMP)
#define XPfree(x)	afree((x).beg, ATEMP)

/* for print_columns */

struct columnise_opts {
	struct shf *shf;
	char linesep;
	bool do_last;
	bool prefcol;
};

/*
 * Lexer internals
 */

typedef struct source Source;
struct source {
	/* input buffer */
	XString xs;
	/* memory area, also checked in reclaim() */
	Area *areap;
	/* stacked source */
	Source *next;
	/* input pointer */
	const char *str;
	/* start of current buffer */
	const char *start;
	/* input file name */
	const char *file;
	/* extra data */
	union {
		/* string[] */
		const char **strv;
		/* shell file */
		struct shf *shf;
		/* alias (SF_HASALIAS) */
		struct tbl *tblp;
		/* (also for SREREAD) */
		char *freeme;
	} u;
	/* flags */
	int flags;
	/* input type */
	int type;
	/* line number */
	int line;
	/* line the error occurred on (0 if not set) */
	int errline;
	/* buffer for ungetsc() (SREREAD) and alias (SALIAS) */
	char ugbuf[2];
};

/* Source.type values */
#define SEOF		0	/* input EOF */
#define SFILE		1	/* file input */
#define SSTDIN		2	/* read stdin */
#define SSTRING		3	/* string */
#define SWSTR		4	/* string without \n */
#define SWORDS		5	/* string[] */
#define SWORDSEP	6	/* string[] separator */
#define SALIAS		7	/* alias expansion */
#define SREREAD		8	/* read ahead to be re-scanned */
#define SSTRINGCMDLINE	9	/* string from "mksh -c ..." */

/* Source.flags values */
#define SF_ECHO		BIT(0)	/* echo input to shlout */
#define SF_ALIAS	BIT(1)	/* faking space at end of alias */
#define SF_ALIASEND	BIT(2)	/* faking space at end of alias */
#define SF_TTY		BIT(3)	/* type == SSTDIN & it is a tty */
#define SF_HASALIAS	BIT(4)	/* u.tblp valid (SALIAS, SEOF) */
#define SF_MAYEXEC	BIT(5)	/* special sh -c optimisation hack */

typedef union {
	int i;
	char *cp;
	char **wp;
	struct op *o;
	struct ioword *iop;
} YYSTYPE;

/* If something is added here, add it to tokentab[] in syn.c as well */
#define LWORD		256
#define LOGAND		257	/* && */
#define LOGOR		258	/* || */
#define BREAK		259	/* ;; */
#define IF		260
#define THEN		261
#define ELSE		262
#define ELIF		263
#define FI		264
#define CASE		265
#define ESAC		266
#define FOR		267
#define SELECT		268
#define WHILE		269
#define UNTIL		270
#define DO		271
#define DONE		272
#define IN		273
#define FUNCTION	274
#define TIME		275
#define REDIR		276
#define MDPAREN		277	/* (( )) */
#define BANG		278	/* ! */
#define DBRACKET	279	/* [[ .. ]] */
#define COPROC		280	/* |& */
#define BRKEV		281	/* ;| */
#define BRKFT		282	/* ;& */
#define YYERRCODE	300

/* flags to yylex */
#define CONTIN		BIT(0)	/* skip new lines to complete command */
#define ONEWORD		BIT(1)	/* single word for substitute() */
#define ALIAS		BIT(2)	/* recognise alias */
#define KEYWORD		BIT(3)	/* recognise keywords */
#define LETEXPR		BIT(4)	/* get expression inside (( )) */
#define CMDASN		BIT(5)	/* parse x[1 & 2] as one word, for typeset */
#define HEREDOC 	BIT(6)	/* parsing a here document body */
#define ESACONLY	BIT(7)	/* only accept esac keyword */
#define CMDWORD		BIT(8)	/* parsing simple command (alias related) */
#define HEREDELIM	BIT(9)	/* parsing <<,<<- delimiter */
#define LQCHAR		BIT(10)	/* source string contains QCHAR */

#define HERES		10	/* max number of << in line */

#ifdef MKSH_EBCDIC
#define CTRL_AT	(0x00U)
#define CTRL_A	(0x01U)
#define CTRL_B	(0x02U)
#define CTRL_C	(0x03U)
#define CTRL_D	(0x37U)
#define CTRL_E	(0x2DU)
#define CTRL_F	(0x2EU)
#define CTRL_G	(0x2FU)
#define CTRL_H	(0x16U)
#define CTRL_I	(0x05U)
#define CTRL_J	(0x15U)
#define CTRL_K	(0x0BU)
#define CTRL_L	(0x0CU)
#define CTRL_M	(0x0DU)
#define CTRL_N	(0x0EU)
#define CTRL_O	(0x0FU)
#define CTRL_P	(0x10U)
#define CTRL_Q	(0x11U)
#define CTRL_R	(0x12U)
#define CTRL_S	(0x13U)
#define CTRL_T	(0x3CU)
#define CTRL_U	(0x3DU)
#define CTRL_V	(0x32U)
#define CTRL_W	(0x26U)
#define CTRL_X	(0x18U)
#define CTRL_Y	(0x19U)
#define CTRL_Z	(0x3FU)
#define CTRL_BO	(0x27U)
#define CTRL_BK	(0x1CU)
#define CTRL_BC	(0x1DU)
#define CTRL_CA	(0x1EU)
#define CTRL_US	(0x1FU)
#define CTRL_QM	(0x07U)
#else
#define CTRL_AT	(0x00U)
#define CTRL_A	(0x01U)
#define CTRL_B	(0x02U)
#define CTRL_C	(0x03U)
#define CTRL_D	(0x04U)
#define CTRL_E	(0x05U)
#define CTRL_F	(0x06U)
#define CTRL_G	(0x07U)
#define CTRL_H	(0x08U)
#define CTRL_I	(0x09U)
#define CTRL_J	(0x0AU)
#define CTRL_K	(0x0BU)
#define CTRL_L	(0x0CU)
#define CTRL_M	(0x0DU)
#define CTRL_N	(0x0EU)
#define CTRL_O	(0x0FU)
#define CTRL_P	(0x10U)
#define CTRL_Q	(0x11U)
#define CTRL_R	(0x12U)
#define CTRL_S	(0x13U)
#define CTRL_T	(0x14U)
#define CTRL_U	(0x15U)
#define CTRL_V	(0x16U)
#define CTRL_W	(0x17U)
#define CTRL_X	(0x18U)
#define CTRL_Y	(0x19U)
#define CTRL_Z	(0x1AU)
#define CTRL_BO	(0x1BU)
#define CTRL_BK	(0x1CU)
#define CTRL_BC	(0x1DU)
#define CTRL_CA	(0x1EU)
#define CTRL_US	(0x1FU)
#define CTRL_QM	(0x7FU)
#endif

#define IDENT	64

EXTERN Source *source;		/* yyparse/yylex source */
EXTERN YYSTYPE yylval;		/* result from yylex */
EXTERN struct ioword *heres[HERES], **herep;
EXTERN char ident[IDENT + 1];

EXTERN char **history;		/* saved commands */
EXTERN char **histptr;		/* last history item */
EXTERN mksh_ari_t histsize;	/* history size */

/* flags to histsave */
#define HIST_FLUSH	0
#define HIST_QUEUE	1
#define HIST_APPEND	2
#define HIST_STORE	3
#define HIST_NOTE	4

/* user and system time of last j_waitjed job */
EXTERN struct timeval j_usrtime, j_systime;

#define notok2mul(max,val,c)	(((val) != 0) && ((c) != 0) && \
				    (((max) / (c)) < (val)))
#define notok2add(max,val,c)	((val) > ((max) - (c)))
#define notoktomul(val,cnst)	notok2mul(SIZE_MAX, (val), (cnst))
#define notoktoadd(val,cnst)	notok2add(SIZE_MAX, (val), (cnst))
#define checkoktoadd(val,cnst) do {					\
	if (notoktoadd((val), (cnst)))					\
		internal_errorf(Tintovfl, (size_t)(val),		\
		    '+', (size_t)(cnst));				\
} while (/* CONSTCOND */ 0)


/* lalloc.c */
void ainit(Area *);
void afreeall(Area *);
/* these cannot fail and can take NULL (not for ap) */
#define alloc(n,ap)		aresize(NULL, (n), (ap))
#define alloc2(m,n,ap)		aresize2(NULL, (m), (n), (ap))
void *aresize(void *, size_t, Area *);
void *aresize2(void *, size_t, size_t, Area *);
void afree(void *, Area *);	/* can take NULL */
#define aresizeif(z,p,n,ap)	(((p) == NULL) || ((z) < (n)) || \
				    (((z) & ~X_WASTE) > ((n) & ~X_WASTE)) ? \
				    aresize((p), (n), (ap)) : (p))
/* edit.c */
#ifndef MKSH_NO_CMDLINE_EDITING
int x_bind(const char * SMALLP(bool));
int x_bind_check(void);
int x_bind_list(void);
int x_bind_showall(void);
void x_init(void);
#ifdef DEBUG_LEAKS
void x_done(void);
#endif
int x_read(char *);
#endif
void x_mkraw(int, mksh_ttyst *, bool);
void x_initterm(const char *);
/* eval.c */
char *substitute(const char *, int);
char **eval(const char **, int);
char *evalstr(const char *cp, int);
char *evalonestr(const char *cp, int);
char *debunk(char *, const char *, size_t);
void expand(const char *, XPtrV *, int);
int glob_str(char *, XPtrV *, bool);
char *do_tilde(char *);
/* exec.c */
int execute(struct op * volatile, volatile int, volatile int * volatile);
int c_builtin(const char **);
struct tbl *get_builtin(const char *);
struct tbl *findfunc(const char *, uint32_t, bool);
int define(const char *, struct op *);
const char *builtin(const char *, int (*)(const char **));
struct tbl *findcom(const char *, int);
void flushcom(bool);
int search_access(const char *, int);
const char *search_path(const char *, const char *, int, int *);
void pr_menu(const char * const *);
void pr_list(struct columnise_opts *, char * const *);
int herein(struct ioword *, char **);
/* expr.c */
int evaluate(const char *, mksh_ari_t *, int, bool);
int v_evaluate(struct tbl *, const char *, volatile int, bool);
/* UTF-8 stuff */
size_t utf_mbtowc(unsigned int *, const char *);
size_t utf_wctomb(char *, unsigned int);
int utf_widthadj(const char *, const char **);
size_t utf_mbswidth(const char *) MKSH_A_PURE;
const char *utf_skipcols(const char *, int, int *);
size_t utf_ptradj(const char *) MKSH_A_PURE;
#ifdef MIRBSD_BOOTFLOPPY
#define utf_wcwidth(i) wcwidth((wchar_t)(i))
#else
int utf_wcwidth(unsigned int) MKSH_A_PURE;
#endif
int ksh_access(const char *, int);
struct tbl *tempvar(const char *);
/* funcs.c */
int c_hash(const char **);
int c_pwd(const char **);
int c_print(const char **);
#ifdef MKSH_PRINTF_BUILTIN
int c_printf(const char **);
#endif
int c_whence(const char **);
int c_command(const char **);
int c_typeset(const char **);
bool valid_alias_name(const char *);
int c_alias(const char **);
int c_unalias(const char **);
int c_let(const char **);
int c_jobs(const char **);
#ifndef MKSH_UNEMPLOYED
int c_fgbg(const char **);
#endif
int c_kill(const char **);
void getopts_reset(int);
int c_getopts(const char **);
#ifndef MKSH_NO_CMDLINE_EDITING
int c_bind(const char **);
#endif
int c_shift(const char **);
int c_umask(const char **);
int c_dot(const char **);
int c_wait(const char **);
int c_read(const char **);
int c_eval(const char **);
int c_trap(const char **);
int c_brkcont(const char **);
int c_exitreturn(const char **);
int c_set(const char **);
int c_unset(const char **);
int c_ulimit(const char **);
int c_times(const char **);
int timex(struct op *, int, volatile int *);
void timex_hook(struct op *, char ** volatile *);
int c_exec(const char **);
int c_test(const char **);
#if HAVE_MKNOD
int c_mknod(const char **);
#endif
int c_realpath(const char **);
int c_rename(const char **);
int c_cat(const char **);
int c_sleep(const char **);
/* histrap.c */
void init_histvec(void);
void hist_init(Source *);
#if HAVE_PERSISTENT_HISTORY
void hist_finish(void);
#endif
void histsave(int *, const char *, int, bool);
#if !defined(MKSH_SMALL) && HAVE_PERSISTENT_HISTORY
bool histsync(void);
#endif
int c_fc(const char **);
void sethistsize(mksh_ari_t);
#if HAVE_PERSISTENT_HISTORY
void sethistfile(const char *);
#endif
#if !defined(MKSH_NO_CMDLINE_EDITING) && !MKSH_S_NOVI
char **histpos(void) MKSH_A_PURE;
int histnum(int);
#endif
int findhist(int, int, const char *, bool) MKSH_A_PURE;
char **hist_get_newest(bool);
void inittraps(void);
void alarm_init(void);
Trap *gettrap(const char *, bool, bool);
void trapsig(int);
void intrcheck(void);
int fatal_trap_check(void);
int trap_pending(void);
void runtraps(int intr);
void runtrap(Trap *, bool);
void cleartraps(void);
void restoresigs(void);
void settrap(Trap *, const char *);
bool block_pipe(void);
void restore_pipe(void);
int setsig(Trap *, sig_t, int);
void setexecsig(Trap *, int);
#if HAVE_FLOCK || HAVE_LOCK_FCNTL
void mksh_lockfd(int);
void mksh_unlkfd(int);
#endif
/* jobs.c */
void j_init(void);
void j_exit(void);
#ifndef MKSH_UNEMPLOYED
void j_change(void);
#endif
int exchild(struct op *, int, volatile int *, int);
void startlast(void);
int waitlast(void);
int waitfor(const char *, int *);
int j_kill(const char *, int);
#ifndef MKSH_UNEMPLOYED
int j_resume(const char *, int);
#endif
#if !defined(MKSH_UNEMPLOYED) && HAVE_GETSID
void j_suspend(void);
#endif
int j_jobs(const char *, int, int);
void j_notify(void);
pid_t j_async(void);
int j_stopped_running(void);
/* lex.c */
int yylex(int);
void yyskiputf8bom(void);
void yyerror(const char *, ...)
    MKSH_A_NORETURN
    MKSH_A_FORMAT(__printf__, 1, 2);
Source *pushs(int, Area *);
void set_prompt(int, Source *);
int pprompt(const char *, int);
/* main.c */
int include(const char *, int, const char **, bool);
int command(const char *, int);
int shell(Source * volatile, volatile int);
/* argument MUST NOT be 0 */
void unwind(int) MKSH_A_NORETURN;
void newenv(int);
void quitenv(struct shf *);
void cleanup_parents_env(void);
void cleanup_proc_env(void);
void errorf(const char *, ...)
    MKSH_A_NORETURN
    MKSH_A_FORMAT(__printf__, 1, 2);
void errorfx(int, const char *, ...)
    MKSH_A_NORETURN
    MKSH_A_FORMAT(__printf__, 2, 3);
void warningf(bool, const char *, ...)
    MKSH_A_FORMAT(__printf__, 2, 3);
void bi_errorf(const char *, ...)
    MKSH_A_FORMAT(__printf__, 1, 2);
void maybe_errorf(int *, int, const char *, ...)
    MKSH_A_FORMAT(__printf__, 3, 4);
#define errorfz()	errorf(NULL)
#define errorfxz(rc)	errorfx((rc), NULL)
#define bi_errorfz()	bi_errorf(NULL)
void internal_errorf(const char *, ...)
    MKSH_A_NORETURN
    MKSH_A_FORMAT(__printf__, 1, 2);
void internal_warningf(const char *, ...)
    MKSH_A_FORMAT(__printf__, 1, 2);
void error_prefix(bool);
void shellf(const char *, ...)
    MKSH_A_FORMAT(__printf__, 1, 2);
void shprintf(const char *, ...)
    MKSH_A_FORMAT(__printf__, 1, 2);
int can_seek(int);
void initio(void);
void recheck_ctype(void);
int ksh_dup2(int, int, bool);
short savefd(int);
void restfd(int, int);
void openpipe(int *);
void closepipe(int *);
int check_fd(const char *, int, const char **);
void coproc_init(void);
void coproc_read_close(int);
void coproc_readw_close(int);
void coproc_write_close(int);
int coproc_getfd(int, const char **);
void coproc_cleanup(int);
struct temp *maketemp(Area *, Temp_type, struct temp **);
void ktinit(Area *, struct table *, uint8_t);
struct tbl *ktscan(struct table *, const char *, uint32_t, struct tbl ***);
/* table, name (key) to search for, hash(n) */
#define ktsearch(tp,s,h) ktscan((tp), (s), (h), NULL)
struct tbl *ktenter(struct table *, const char *, uint32_t);
#define ktdelete(p)	do { p->flag = 0; } while (/* CONSTCOND */ 0)
void ktwalk(struct tstate *, struct table *);
struct tbl *ktnext(struct tstate *);
struct tbl **ktsort(struct table *);
#ifdef DF
void DF(const char *, ...)
    MKSH_A_FORMAT(__printf__, 1, 2);
#endif
/* misc.c */
size_t option(const char *) MKSH_A_PURE;
char *getoptions(void);
void change_flag(enum sh_flag, int, bool);
void change_xtrace(unsigned char, bool);
int parse_args(const char **, int, bool *);
int getn(const char *, int *);
int gmatchx(const char *, const char *, bool);
bool has_globbing(const char *) MKSH_A_PURE;
int ascstrcmp(const void *, const void *) MKSH_A_PURE;
int ascpstrcmp(const void *, const void *) MKSH_A_PURE;
void ksh_getopt_reset(Getopt *, int);
int ksh_getopt(const char **, Getopt *, const char *);
void print_value_quoted(struct shf *, const char *);
char *quote_value(const char *);
void print_columns(struct columnise_opts *, unsigned int,
    void (*)(char *, size_t, unsigned int, const void *),
    const void *, size_t, size_t);
void strip_nuls(char *, size_t)
    MKSH_A_BOUNDED(__string__, 1, 2);
ssize_t blocking_read(int, char *, size_t)
    MKSH_A_BOUNDED(__buffer__, 2, 3);
int reset_nonblock(int);
char *ksh_get_wd(void);
char *do_realpath(const char *);
void simplify_path(char *);
void set_current_wd(const char *);
int c_cd(const char **);
#if defined(MKSH_SMALL) && !defined(MKSH_SMALL_BUT_FAST)
char *strdup_i(const char *, Area *);
char *strndup_i(const char *, size_t, Area *);
#endif
int unbksl(bool, int (*)(void), void (*)(int));
#ifdef __OS2__
/* os2.c */
void os2_init(int *, const char ***);
void setextlibpath(const char *, const char *);
int access_ex(int (*)(const char *, int), const char *, int);
int stat_ex(int (*)(const char *, struct stat *), const char *, struct stat *);
const char *real_exec_name(const char *);
#endif
/* shf.c */
struct shf *shf_open(const char *, int, int, int);
struct shf *shf_fdopen(int, int, struct shf *);
struct shf *shf_reopen(int, int, struct shf *);
struct shf *shf_sopen(char *, ssize_t, int, struct shf *);
int shf_close(struct shf *);
int shf_fdclose(struct shf *);
char *shf_sclose(struct shf *);
int shf_flush(struct shf *);
ssize_t shf_read(char *, ssize_t, struct shf *);
char *shf_getse(char *, ssize_t, struct shf *);
int shf_getchar(struct shf *s);
int shf_ungetc(int, struct shf *);
#ifdef MKSH_SHF_NO_INLINE
int shf_getc(struct shf *);
int shf_putc(int, struct shf *);
#else
#define shf_getc shf_getc_i
#define shf_putc shf_putc_i
#endif
int shf_putchar(int, struct shf *);
ssize_t shf_puts(const char *, struct shf *);
ssize_t shf_write(const char *, ssize_t, struct shf *);
ssize_t shf_fprintf(struct shf *, const char *, ...)
    MKSH_A_FORMAT(__printf__, 2, 3);
ssize_t shf_snprintf(char *, ssize_t, const char *, ...)
    MKSH_A_FORMAT(__printf__, 3, 4)
    MKSH_A_BOUNDED(__string__, 1, 2);
char *shf_smprintf(const char *, ...)
    MKSH_A_FORMAT(__printf__, 1, 2);
ssize_t shf_vfprintf(struct shf *, const char *, va_list)
    MKSH_A_FORMAT(__printf__, 2, 0);
void set_ifs(const char *);
/* syn.c */
void initkeywords(void);
struct op *compile(Source *, bool, bool);
bool parse_usec(const char *, struct timeval *);
char *yyrecursive(int);
void yyrecursive_pop(bool);
/* tree.c */
void fptreef(struct shf *, int, const char *, ...);
char *snptreef(char *, ssize_t, const char *, ...);
struct op *tcopy(struct op *, Area *);
char *wdcopy(const char *, Area *);
const char *wdscan(const char *, int);
#define WDS_TPUTS	BIT(0)		/* tputS (dumpwdvar) mode */
char *wdstrip(const char *, int);
void tfree(struct op *, Area *);
void dumpchar(struct shf *, unsigned char);
void dumptree(struct shf *, struct op *);
void dumpwdvar(struct shf *, const char *);
void dumpioact(struct shf *shf, struct op *t);
void vistree(char *, size_t, struct op *)
    MKSH_A_BOUNDED(__string__, 1, 2);
void fpFUNCTf(struct shf *, int, bool, const char *, struct op *);
/* var.c */
void newblock(void);
void popblock(void);
void initvar(void);
struct block *varsearch(struct block *, struct tbl **, const char *, uint32_t);
struct tbl *global(const char *);
struct tbl *isglobal(const char *, bool);
struct tbl *local(const char *, bool);
char *str_val(struct tbl *);
int setstr(struct tbl *, const char *, int);
struct tbl *setint_v(struct tbl *, struct tbl *, bool);
void setint(struct tbl *, mksh_ari_t);
void setint_n(struct tbl *, mksh_ari_t, int);
struct tbl *typeset(const char *, uint32_t, uint32_t, int, int);
void unset(struct tbl *, int);
const char *skip_varname(const char *, bool) MKSH_A_PURE;
const char *skip_wdvarname(const char *, bool) MKSH_A_PURE;
int is_wdvarname(const char *, bool) MKSH_A_PURE;
int is_wdvarassign(const char *) MKSH_A_PURE;
struct tbl *arraysearch(struct tbl *, uint32_t);
char **makenv(void);
void change_winsz(void);
size_t array_ref_len(const char *) MKSH_A_PURE;
char *arrayname(const char *);
mksh_uari_t set_array(const char *, bool, const char **);
uint32_t hash(const void *) MKSH_A_PURE;
uint32_t chvt_rndsetup(const void *, size_t) MKSH_A_PURE;
mksh_ari_t rndget(void);
void rndset(unsigned long);
void rndpush(const void *);
void record_match(const char *);

enum Test_op {
	/* non-operator */
	TO_NONOP = 0,
	/* unary operators */
	TO_STNZE, TO_STZER, TO_ISSET, TO_OPTION,
	TO_FILAXST,
	TO_FILEXST,
	TO_FILREG, TO_FILBDEV, TO_FILCDEV, TO_FILSYM, TO_FILFIFO, TO_FILSOCK,
	TO_FILCDF, TO_FILID, TO_FILGID, TO_FILSETG, TO_FILSTCK, TO_FILUID,
	TO_FILRD, TO_FILGZ, TO_FILTT, TO_FILSETU, TO_FILWR, TO_FILEX,
	/* binary operators */
	TO_STEQL, TO_STNEQ, TO_STLT, TO_STGT, TO_INTEQ, TO_INTNE, TO_INTGT,
	TO_INTGE, TO_INTLT, TO_INTLE, TO_FILEQ, TO_FILNT, TO_FILOT,
	/* not an operator */
	TO_NONNULL	/* !TO_NONOP */
};
typedef enum Test_op Test_op;

/* Used by Test_env.isa() (order important - used to index *_tokens[] arrays) */
enum Test_meta {
	TM_OR,		/* -o or || */
	TM_AND,		/* -a or && */
	TM_NOT,		/* ! */
	TM_OPAREN,	/* ( */
	TM_CPAREN,	/* ) */
	TM_UNOP,	/* unary operator */
	TM_BINOP,	/* binary operator */
	TM_END		/* end of input */
};
typedef enum Test_meta Test_meta;

struct t_op {
	const char op_text[4];
	Test_op op_num;
};

/* for string reuse */
extern const struct t_op u_ops[];
extern const struct t_op b_ops[];
/* ensure order with funcs.c */
#define Tda (u_ops[0].op_text)
#define Tdn (u_ops[12].op_text)
#define Tdo (u_ops[14].op_text)
#define Tdr (u_ops[16].op_text)
#define Tdu (u_ops[20].op_text)	/* "-u" */
#define Tdx (u_ops[23].op_text)

#define Tu (Tdu + 1)	/* "u" */

#define TEF_ERROR	BIT(0)		/* set if we've hit an error */
#define TEF_DBRACKET	BIT(1)		/* set if [[ .. ]] test */

typedef struct test_env {
	union {
		const char **wp;	/* used by ptest_* */
		XPtrV *av;		/* used by dbtestp_* */
	} pos;
	const char **wp_end;		/* used by ptest_* */
	Test_op (*isa)(struct test_env *, Test_meta);
	const char *(*getopnd) (struct test_env *, Test_op, bool);
	int (*eval)(struct test_env *, Test_op, const char *, const char *, bool);
	void (*error)(struct test_env *, int, const char *);
	int flags;			/* TEF_* */
} Test_env;

extern const char * const dbtest_tokens[];

Test_op	test_isop(Test_meta, const char *) MKSH_A_PURE;
int test_eval(Test_env *, Test_op, const char *, const char *, bool);
int test_parse(Test_env *);

/* tty_fd is not opened O_BINARY, it's thus never read/written */
EXTERN int tty_fd E_INIT(-1);	/* dup'd tty file descriptor */
EXTERN bool tty_devtty;		/* true if tty_fd is from /dev/tty */
EXTERN mksh_ttyst tty_state;	/* saved tty state */
EXTERN bool tty_hasstate;	/* true if tty_state is valid */

extern int tty_init_fd(void);	/* initialise tty_fd, tty_devtty */

#ifdef __OS2__
#define binopen2(path,flags)		__extension__({			\
	int binopen2_fd = open((path), (flags) | O_BINARY);		\
	if (binopen2_fd >= 0)						\
		setmode(binopen2_fd, O_BINARY);				\
	(binopen2_fd);							\
})
#define binopen3(path,flags,mode)	__extension__({			\
	int binopen3_fd = open((path), (flags) | O_BINARY, (mode));	\
	if (binopen3_fd >= 0)						\
		setmode(binopen3_fd, O_BINARY);				\
	(binopen3_fd);							\
})
#else
#define binopen2(path,flags)		open((path), (flags) | O_BINARY)
#define binopen3(path,flags,mode)	open((path), (flags) | O_BINARY, (mode))
#endif

#ifdef MKSH_DOSPATH
#define mksh_drvltr(s)			__extension__({			\
	const char *mksh_drvltr_s = (s);				\
	(ctype(mksh_drvltr_s[0], C_ALPHA) && mksh_drvltr_s[1] == ':');	\
})
#define mksh_abspath(s)			__extension__({			\
	const char *mksh_abspath_s = (s);				\
	(mksh_cdirsep(mksh_abspath_s[0]) ||				\
	    (mksh_drvltr(mksh_abspath_s) &&				\
	    mksh_cdirsep(mksh_abspath_s[2])));				\
})
#define mksh_cdirsep(c)			__extension__({			\
	char mksh_cdirsep_c = (c);					\
	(mksh_cdirsep_c == '/' || mksh_cdirsep_c == '\\');		\
})
#define mksh_sdirsep(s)			strpbrk((s), "/\\")
#define mksh_vdirsep(s)			__extension__({			\
	const char *mksh_vdirsep_s = (s);				\
	(((mksh_drvltr(mksh_vdirsep_s) &&				\
	    !mksh_cdirsep(mksh_vdirsep_s[2])) ? (!0) :			\
	    (mksh_sdirsep(mksh_vdirsep_s) != NULL)) &&			\
	    (strcmp(mksh_vdirsep_s, T_builtin) != 0));			\
})
int getdrvwd(char **, unsigned int);
#else
#define mksh_abspath(s)			(ord((s)[0]) == ORD('/'))
#define mksh_cdirsep(c)			(ord(c) == ORD('/'))
#define mksh_sdirsep(s)			strchr((s), '/')
#define mksh_vdirsep(s)			vstrchr((s), '/')
#endif

/* be sure not to interfere with anyone else's idea about EXTERN */
#ifdef EXTERN_DEFINED
# undef EXTERN_DEFINED
# undef EXTERN
#endif
#undef E_INIT

#endif /* !MKSH_INCLUDES_ONLY */
