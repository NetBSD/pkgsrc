dnl $Id: configure.ac,v 1.1.1.1 2003/08/18 17:34:57 agc Exp $
dnl Process this file with autoconf to produce a configure script.
AC_PREREQ(2.57)
AC_INIT([nb-sed],[20030818],[agc@netbsd.org])
AC_CONFIG_SRCDIR([main.c])
AC_CONFIG_HEADER(config.h)
AC_ARG_PROGRAM

AC_CANONICAL_HOST
CANONICAL_HOST=$host
AC_SUBST(CANONICAL_HOST)

# Checks for programs.
AC_PROG_MAKE_SET
AC_PROG_AWK
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S

AUTOCONF=${AUTOCONF-"$srcdir/missing --run autoconf"}
AC_SUBST(AUTOCONF)
AUTOHEADER=${AUTOHEADER-"$srcdir/missing --run autoheader"}
AC_SUBST(AUTOHEADER)

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([ctype.h errno.h fcntl.h limits.h regex.h])
AC_CHECK_HEADERS([stdlib.h stddef.h string.h sys/cdefs.h])
AC_CHECK_HEADERS([sys/ioctl.h sys/termios.h sys/uio.h])

dnl Check for functions
AC_CHECK_FUNCS(fgetln)
AC_CHECK_FUNCS(regcomp)
AC_CHECK_FUNCS(regexec)
AC_CHECK_FUNCS(getprogname)
AC_CHECK_FUNCS(setprogname)

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_STRERROR_R
AC_FUNC_VPRINTF
AC_CHECK_FUNCS([bcopy bzero memset memcpy setlocale])
#
AH_BOTTOM([

#ifndef HAVE___ATTRIBUTE__
# define __attribute__(x)
#endif

#ifdef HAVE_SYS_CDEFS_H
#include <sys/cdefs.h>
#endif

#ifndef __IDSTRING
# define __IDSTRING(name,string) \
       static const char name[] __attribute__((__unused__)) = string
#endif

#ifndef  __RCSID
# define __RCSID(_s)     __IDSTRING(rcsid,_s)
#endif

#ifndef __COPYRIGHT
# define __COPYRIGHT(_s) __IDSTRING(copyright,_s)
#endif

#ifndef __P
# if defined(__STDC__) || defined(__cplusplus)
#  define __P(protos)     protos          /* full-blown ANSI C */
# else
#  define __P(protos)     ()              /* traditional C preprocessor */
# endif
#endif

#ifndef __CONCAT
#  if defined(__STDC__) || defined(__cplusplus)
#  define __CONCAT(x,y)   x ## y
# else
#  define __CONCAT(x,y)   x/**/y
# endif
#endif

#ifndef __BEGIN_DECLS
# if defined(__cplusplus)
#  define __BEGIN_DECLS   extern "C" {
# else
#  define __BEGIN_DECLS
# endif
#endif

#ifndef __END_DECLS
# if defined(__cplusplus)
#  define __END_DECLS     };
# else
#  define __END_DECLS
# endif
#endif

#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif

#if defined(HAVE_MEMSET)
#define MEMSET_BZERO(p,l)	memset((p), 0, (l))
#else
# if defined(HAVE_BZERO)
#define MEMSET_BZERO(p,l)	bzero((p), (l))
# else
#error You need either memset or bzero
# endif
#endif

#if defined(HAVE_MEMCPY)
#define MEMCPY_BCOPY(d,s,l)	memcpy((d), (s), (l))
#else
# if defined(HAVE_BCOPY)
#define MEMCPY_BCOPY(d,s,l)	bcopy((s), (d), (l))
# else
#error You need either memcpy or bcopy
# endif
#endif
])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
