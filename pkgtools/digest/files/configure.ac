dnl $Id: configure.ac,v 1.17 2011/11/04 23:58:14 cheusov Exp $
dnl Process this file with autoconf to produce a configure script.
AC_PREREQ(2.57)
AC_INIT([nbsd-digest],[20111104],[agc@netbsd.org])
AC_CONFIG_SRCDIR([digest.c])
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
AC_CHECK_HEADERS([errno.h fcntl.h inttypes.h locale.h stdlib.h])
AC_CHECK_HEADERS([sys/cdefs.h sys/file.h sys/param.h])

AC_TYPE_UINT8_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_INT64_T
AC_TYPE_UINT64_T

AC_C_BIGENDIAN

# Checks for library functions.
AC_FUNC_STRERROR_R
AC_FUNC_VPRINTF
AC_CHECK_FUNCS([bcopy bzero memset memcpy setlocale])
#
AH_BOTTOM([
#ifdef HAVE_SYS_CDEFS_H
#include <sys/cdefs.h>
#endif

#if defined(__GNUC__) && !defined(__IDSTRING)
#if (__GNUC__ == 2 && __GNUC_MINOR >= 7) || (__GNUC__ > 2)
# define __IDSTRING(name,string) \
       static const char name[] __attribute__((__unused__)) = string
#endif
#endif

#ifndef __IDSTRING
# define __IDSTRING(name,string) \
       static const char name[] = string
#endif

#ifndef  __RCSID
# define __RCSID(_s)     __IDSTRING(rcsid,_s)
#endif

#ifndef __COPYRIGHT
# define __COPYRIGHT(_s) __IDSTRING(copyright,_s)
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
