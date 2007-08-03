#Process this file with autoconf to produce a configure script.

# M4 magic to pull in the version from a separate file
# so we don't have to edit this file for routine version updates
m4_define([ARCHIVE_VERS],m4_include([version]))

AC_INIT([libarchive],ARCHIVE_VERS(),[kientzle@freebsd.org])
# Make sure the srcdir contains "libarchive" directory
AC_CONFIG_SRCDIR([libarchive])
# Use auxiliary subscripts from this subdirectory (cleans up root)
AC_CONFIG_AUX_DIR([config.aux])
# Must follow AC_CONFIG macros above...
AM_INIT_AUTOMAKE()

# Shell magic to compute Major/minor/etc from full version stamp.
# This gets a little hairy...
AC_CONFIG_COMMANDS_PRE([
# Autoconf assigns the version above to PACKAGE_VERSION
ARCHIVE_VERSION=$PACKAGE_VERSION

# Peel off first three numbers major.minor.revision
ARCHIVE_MAJOR=`echo $ARCHIVE_VERSION | sed -e 's/[[^0-9]]/./g' -e 's/\..*//'`
ARCHIVE_MINOR=`echo $ARCHIVE_VERSION | sed -e 's/[[^0-9]]/./g' -e 's/^[[0-9]]*\.//' -e 's/\..*//'`
ARCHIVE_REVISION=`echo $ARCHIVE_VERSION | sed -e 's/[[^0-9]]/./g' -e 's/^[[0-9]]*\.[[0-9]]*\.//' -e 's/\..*//'`
# Major/minor indicate the API version
ARCHIVE_API_MAJOR=$ARCHIVE_MAJOR
ARCHIVE_API_MINOR=$ARCHIVE_MINOR
ARCHIVE_VERSION_STAMP=`printf "%d%03d%03d" ${ARCHIVE_MAJOR} ${ARCHIVE_MINOR} ${ARCHIVE_REVISION}`
# Libtool versioning uses different conventions on different platforms.
# FreeBSD libtool still uses this old (and very dumb) convention,
# which doesn't match FreeBSD system conventions, nor anything else
# I'm familiar with.
ARCHIVE_LIBTOOL_MAJOR=`echo $((${ARCHIVE_MAJOR} + ${ARCHIVE_MINOR}))`
ARCHIVE_LIBTOOL_VERSION=$ARCHIVE_LIBTOOL_MAJOR:$ARCHIVE_REVISION:$ARCHIVE_MINOR
])

# Substitute the above version numbers into the various files below.
AC_SUBST(ARCHIVE_VERSION)
AC_SUBST(ARCHIVE_MAJOR)
AC_SUBST(ARCHIVE_MINOR)
AC_SUBST(ARCHIVE_REVISION)
AC_SUBST(ARCHIVE_API_MAJOR)
AC_SUBST(ARCHIVE_API_MINOR)
AC_SUBST(ARCHIVE_VERSION_STAMP)
AC_SUBST(ARCHIVE_LIBTOOL_VERSION)

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([libarchive/archive.h])

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_YACC
AC_PROG_LIBTOOL
AC_CHECK_TOOL([STRIP],[strip])

AC_ARG_ENABLE([bsdtar],
	[AS_HELP_STRING([--disable-bsdtar], [disable build of bsdtar])],
	[], [])

case "$enable_bsdtar" in
yes)
	if test "$enable_static" = "no"; then
		static_bsdtar=no
	else
		static_bsdtar=yes
	fi
	build_bsdtar=yes

	;;
shared)
	if test "$enable_shared" = "no"; then
		AC_MSG_FAILURE([Shared linking of bsdtar requires shared libarchive])
	fi
	build_bsdtar=yes
	static_bsdtar=no
	;;
no)
	build_bsdtar=no
	static_bsdtar=no
	;;
*)
	AC_MSG_FAILURE([Unsupported value for --enable-bsdtar])
	;;
esac

AM_CONDITIONAL([BUILD_BSDTAR], [ test "$build_bsdtar" = yes ])
AM_CONDITIONAL([STATIC_BSDTAR], [ test "$static_bsdtar" = yes ])

# Checks for header files.
AC_HEADER_STDC
AC_HEADER_DIRENT
AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS([attr/xattr.h])
AC_CHECK_HEADERS([bzlib.h errno.h ext2fs/ext2_fs.h fcntl.h  grp.h])
AC_CHECK_HEADERS([inttypes.h langinfo.h limits.h linux/ext2_fs.h linux/fs.h])
# Include inttypes.h into archive.h only if appropriate.
# We can't use the HAVE_INTTYPES_H macro here because archive.h
# gets installed as a system header and then included into client code
# that doesn't define such macros.  (And we should certainly not
# define such macros in system headers!)
# Hence the following:
AC_CHECK_HEADER(inttypes.h,
	 [AC_SUBST(ARCHIVE_H_INCLUDE_INTTYPES_H,['#include <inttypes.h> /* For int64_t */'])],
	 [AC_SUBST(ARCHIVE_H_INCLUDE_INTTYPES_H,[''])])
AC_CHECK_HEADERS([locale.h paths.h poll.h pwd.h stdarg.h])
AC_CHECK_HEADERS([stdint.h stdlib.h string.h sys/acl.h sys/ioctl.h])
AC_CHECK_HEADERS([sys/param.h sys/select.h sys/time.h])
AC_CHECK_HEADERS([time.h unistd.h utime.h wchar.h zlib.h])

# Checks for libraries.
AC_CHECK_LIB(acl,acl_set_file)
AC_CHECK_LIB(attr,setxattr)
AC_CHECK_LIB(bz2,BZ2_bzDecompressInit)
AC_CHECK_LIB(z,inflate)

# TODO: Give the user the option of using a pre-existing system
# libarchive.  This will define HAVE_LIBARCHIVE which will cause
# bsdtar_platform.h to use #include <...> for the libarchive headers.
# Need to include Makefile.am magic to link against system
# -larchive in that case.
#AC_CHECK_LIB(archive,archive_version)

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_UID_T
AC_TYPE_MODE_T
# AC_TYPE_OFF_T defaults to "long", which limits us to 4GB files on
# most systems...
AC_CHECK_TYPE(off_t, [int64_t])
AC_TYPE_SIZE_T
AC_CHECK_TYPE(id_t, [unsigned long])
AC_CHECK_TYPE(uintptr_t, [unsigned int])
AC_CHECK_MEMBERS([struct stat.st_rdev])
AC_CHECK_MEMBERS([struct tm.tm_gmtoff])
# Check for high-resolution timestamps in struct stat
AC_CHECK_MEMBERS([struct stat.st_mtimespec.tv_nsec, struct stat.st_mtim.tv_nsec])

#
# We need int64_t
#
AC_CHECK_TYPE(int64_t)
#
# If int64_t isn't defined, define it in terms of some other 64-bit type.
#
if test "$ac_cv_type_int64_t" != yes; then
  AC_CHECK_TYPE(_int64_t,
	[AC_DEFINE([int64_t], [_int64_t],
              [Define int64_t to a valid signed 64-bit type, if necessary.])])
  if test "$ac_cv_type__int64_t" != yes; then
    AC_CHECK_TYPE(__int64_t,
        [AC_DEFINE([int64_t], [__int64_t],
	      [Define int64_t to a valid signed 64-bit type, if necessary.])])
    if test "$ac_cv_type___int64_t" != yes; then
      AC_CHECK_TYPE(long long,
	  [AC_DEFINE([int64_t], [long long],
	      [Define int64_t to a valid signed 64-bit type, if necessary.])])
    fi
  fi
fi

#
# We need uint64_t
#
AC_CHECK_TYPE(uint64_t)
#
# If uint64_t isn't defined, define it in terms of some other 64-bit type.
#
if test "$ac_cv_type_uint64_t" != yes; then
  AC_CHECK_TYPE(u_int64_t,
     [AC_DEFINE([uint64_t], [u_int64_t],
                [Define uint64_t to an unsigned 64-bit type, if necessary.])])
  if test "$ac_cv_type_u_int64_t" != yes; then
    AC_CHECK_TYPE(_uint64_t,
       [AC_DEFINE([uint64_t], [_uint64_t],
                 [Define uint64_t to an unsigned 64-bit type, if necessary.])])
    if test "$ac_cv_type__uint64_t" != yes; then
      AC_CHECK_TYPE(__uint64_t,
         [AC_DEFINE([uint64_t], [__uint64_t],
                 [Define uint64_t to an unsigned 64-bit type, if necessary.])])
      if test "$ac_cv_type___uint64_t" != yes; then
        AC_CHECK_TYPE(unsigned long long,
	   [AC_DEFINE([uint64_t], [unsigned long long],
                 [Define uint64_t to an unsigned 64-bit type, if necessary.])])
      fi
    fi
  fi
fi

# We need uintmax_t and intmax_t
# Define them in terms of uint64_t and int64_t if appropriate.
AC_CHECK_TYPE(uintmax_t, [uint64_t])
AC_CHECK_TYPE(intmax_t, [int64_t])


# If you have uintmax_t, we assume printf supports %ju
# If you have unsigned long long, we assume printf supports %llu
AC_CHECK_TYPES([uintmax_t, unsigned long long])

# TODO: If any of these are missing, define them right here.
AC_CHECK_DECLS([SIZE_MAX, INT64_MAX, INT64_MIN, UINT64_MAX, UINT32_MAX])

AC_CHECK_DECL([EFTYPE],
		[AC_DEFINE(HAVE_EFTYPE, 1, [A possible errno value for invalid file format errors])],
		[],
		[#include <errno.h>])
AC_CHECK_DECL([EILSEQ],
		[AC_DEFINE(HAVE_EILSEQ, 1, [A possible errno value for invalid file format errors])],
		[],
		[#include <errno.h>])
AC_HEADER_TIME

# Checks for library functions.
AC_PROG_GCC_TRADITIONAL
AC_HEADER_MAJOR
AC_FUNC_FSEEKO
AC_FUNC_MEMCMP
AC_FUNC_LSTAT
AC_FUNC_STAT
AC_FUNC_STRERROR_R
AC_FUNC_STRFTIME
AC_FUNC_VPRINTF
AC_CHECK_FUNCS([chflags fchdir fchflags fchmod fchown futimes])
AC_CHECK_FUNCS([ftruncate getopt_long getxattr])
AC_CHECK_FUNCS([lchflags lchmod lchown])
AC_CHECK_FUNCS([lgetxattr listxattr llistxattr fsetxattr lsetxattr])
AC_CHECK_FUNCS([lutimes memmove memset mkdir mkfifo])
AC_CHECK_FUNCS([nl_langinfo poll reallocf select setlocale])
AC_CHECK_FUNCS([strchr strdup strerror strrchr timegm utime utimes])
AC_CHECK_FUNCS([wcscpy wcslen wmemcmp wmemcpy])

# FreeBSD's nl_langinfo supports an option to specify whether the
# current locale uses month/day or day/month ordering.  It makes the
# output a little prettier...
AC_CHECK_DECL([D_MD_ORDER],
[AC_DEFINE(HAVE_D_MD_ORDER, 1, [Define to 1 if nl_langinfo supports D_MD_ORDER])],
[],
[#if HAVE_LANGINFO_H
#include <langinfo.h>
#endif
])

# If fnmatch() exists and supports FNM_LEADING_DIR, then bsdtar uses that,
# otherwise it uses some usable (but less featureful) built-in code for
# filename pattern matching.
AC_FUNC_FNMATCH
AC_CHECK_DECL([FNM_LEADING_DIR],
[AC_DEFINE(HAVE_FNM_LEADING_DIR, 1, [Define to 1 if fnmatch(3) supports the FNM_LEADING_DIR flag])],
[],
[#if HAVE_FNMATCH
#define _GNU_SOURCE /* Required on Linux to get GNU extensions */
#include <fnmatch.h>
#endif
])

# Check for dirent.d_namlen field explicitly
# (This is a bit more straightforward than, if not quite as portable as,
# the recipe given by the autoconf maintainers.)
AC_CHECK_MEMBER(struct dirent.d_namlen,,,
[#if HAVE_DIRENT_H
#include <dirent.h>
#endif
])

# Check for ACL support
#
# The ACL support in libarchive is written against the POSIX1e draft,
# which was never officially approved and varies quite a bit across
# platforms.  Worse, some systems have completely non-POSIX acl functions,
# which makes the following checks rather more complex than I would like.
#
AC_CHECK_HEADERS([sys/acl.h])
AC_CHECK_LIB([acl],[acl_get_file])
AC_CHECK_FUNCS([acl_create_entry acl_init acl_set_fd acl_set_fd_np acl_set_file])

AC_CHECK_TYPES(acl_permset_t,,,
[#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if HAVE_SYS_ACL_H
#include <sys/acl.h>
#endif
])

# The "acl_get_perm()" function was omitted from the POSIX draft.
# (It's a pretty obvious oversight; otherwise, there's no way to
# test for specific permissions in a permset.)  Linux uses the obvious
# name, FreeBSD adds _np to mark it as "non-Posix extension."
# Test for both as a double-check that we really have POSIX-style ACL support.
AC_CHECK_FUNCS(acl_get_perm_np acl_get_perm,,,
[#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if HAVE_SYS_ACL_H
#include <sys/acl.h>
#endif
])

# MacOS has an acl.h that isn't POSIX.  It can be detected by
# checking for ACL_USER
AC_CHECK_DECL([ACL_USER],
		[AC_DEFINE(HAVE_ACL_USER, 1, [True for systems with POSIX ACL support])],
		[],
		[#include <sys/acl.h>])

# Additional requirements
AC_SYS_LARGEFILE

AC_OUTPUT
