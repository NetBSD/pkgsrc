#                                               -*- Autoconf -*-
# $NetBSD: configure.ac,v 1.1.1.1 2003/06/09 22:16:15 seb Exp $
#
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.57)
AC_INIT([texinfo], [4.5])
AC_CONFIG_SRCDIR([install-info.c])
AC_CONFIG_HEADER([config.h])

# Checks for programs.

# Checks for libraries.

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([fcntl.h limits.h memory.h stdlib.h string.h strings.h sys/file.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STAT
AC_C_CONST
AC_TYPE_SIZE_T

# Checks for library functions.
dnl AC_FUNC_ERROR_AT_LINE
dnl AC_FUNC_MALLOC
dnl AC_FUNC_REALLOC
dnl AC_FUNC_STRCOLL
dnl AC_CHECK_FUNCS([strchr])
AC_REPLACE_FUNCS([strdup strerror strncasecmp])

#
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
