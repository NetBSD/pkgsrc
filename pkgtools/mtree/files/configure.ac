#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.57)
AC_INIT([mtree], [20030905], [grant@NetBSD.org])
AC_CONFIG_SRCDIR([mtree.c])
AC_CONFIG_HEADER([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL

# Checks for libraries.
AC_CHECK_LIB(util, fparseln)

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([fnmatch.h grp.h pwd.h util.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_UID_T
AC_TYPE_MODE_T
AC_TYPE_OFF_T
AC_TYPE_SIZE_T
AC_CHECK_MEMBERS([struct stat.st_rdev])
AC_CHECK_MEMBERS([struct stat.st_flags])
AC_CHECK_DECLS([UF_SETTABLE, SF_SETTABLE])
AH_BOTTOM([/* define HAVE_FILE_FLAGS if the user- and root-changeable masks
were detected */
#if defined(HAVE_STRUCT_STAT_ST_FLAGS) && (HAVE_DECL_UF_SETTABLE == 1) && (HAVE_DECL_SF_SETTABLE == 1)
#define HAVE_FILE_FLAGS 1
#else
#define HAVE_FILE_FLAGS 0
#endif
])
AC_HEADER_TIME

# Checks for library functions.
AC_REPLACE_FNMATCH
AC_CHECK_FUNCS([endgrent endpwent getcwd gethostname mkdir strchr strpbrk strstr strtol strtoul])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
