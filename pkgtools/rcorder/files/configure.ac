dnl $NetBSD: configure.ac,v 1.1 2004/08/27 03:06:07 jlam Exp $
dnl Process this file with autoconf to produce a configure script.
AC_PREREQ(2.57)
AC_INIT([nbsed],[20031013],[agc@NetBSD.org])
AC_CONFIG_SRCDIR([rcorder.c])
AC_CONFIG_HEADER(config.h)
AC_ARG_PROGRAM

AC_CANONICAL_HOST
CANONICAL_HOST=$host
AC_SUBST(CANONICAL_HOST)

# Checks for programs.
AC_PROG_MAKE_SET
AC_PROG_CC
AC_PROG_INSTALL

AUTOCONF=${AUTOCONF-"$srcdir/missing --run autoconf"}
AC_SUBST(AUTOCONF)
AUTOHEADER=${AUTOHEADER-"$srcdir/missing --run autoheader"}
AC_SUBST(AUTOHEADER)

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([err.h stdio.h stdlib.h string.h unistd.h])
AC_CHECK_HEADERS([sys/cdefs.h sys/stat.h sys/types.h])

dnl Checks for libraries.
AC_CHECK_LIB(util, fparseln)

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_SIZE_T

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
