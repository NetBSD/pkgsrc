#                                               -*- Autoconf -*-
# $NetBSD: configure.ac,v 1.3 2005/02/07 16:14:26 seb Exp $
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
AC_CHECK_HEADERS([fcntl.h limits.h locale.h memory.h stdlib.h string.h strings.h sys/file.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STAT
AC_C_CONST
AC_TYPE_SIZE_T

# Checks for library functions.
dnl AC_FUNC_ERROR_AT_LINE
dnl AC_FUNC_MALLOC
dnl AC_FUNC_REALLOC
dnl AC_FUNC_STRCOLL
AC_FUNC_VPRINTF
AC_CHECK_FUNCS([setlocale])
AC_REPLACE_FUNCS([strdup strerror strncasecmp])

#
if test $ac_cv_header_locale_h = yes; then
	AC_CACHE_CHECK([for LC_MESSAGES], am_cv_val_LC_MESSAGES,
		[AC_TRY_LINK([#include <locale.h>], [return LC_MESSAGES],
		am_cv_val_LC_MESSAGES=yes, am_cv_val_LC_MESSAGES=no)]) 
	if test $am_cv_val_LC_MESSAGES = yes; then
		AC_DEFINE(HAVE_LC_MESSAGES, 1, 
			[Define if your <locale.h> file defines LC_MESSAGES.])
	fi
fi


#
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
