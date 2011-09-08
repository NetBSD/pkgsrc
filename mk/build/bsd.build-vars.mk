# $NetBSD: bsd.build-vars.mk,v 1.7 2011/09/08 20:17:15 abs Exp $
#
# Package-settable variables:
#
# BUILD_DIRS is the list of directories in which to perform the build
#	process.  If the directories are relative paths, then they
#	are assumed to be relative to ${WRKSRC}.
#
# MAKE_ENV is the shell environment that is exported to the make
#	process.
#
# MAKE_FLAGS is a list of arguments that is pass to the make process.
#
# MAKE_FILE is the path to the makefile that is processed by the make
#	executable.  If the path is relative, then it is assumed to
#	be relative to each directory listed in BUILD_DIRS.
#
# System-provided variables:
#
# MAKE_PROGRAM is the path to the make executable that is run to
#	process the source makefiles. See mk/tools/make.mk.
#

_VARGROUPS+=		build-vars
_USER_VARS.build-vars=	# none
_PKG_VARS.build-vars=	BUILD_DIRS MAKE_ENV MAKE_PROGRAM MAKE_FLAGS MAKE_FILE NO_BUILD

BUILD_DIRS?=	${CONFIGURE_DIRS}
MAKE_ENV?=	# empty
MAKE_FLAGS?=	# empty
MAKE_FILE?=	Makefile

MAKE_ENV+=	${ALL_ENV}
MAKE_ENV+=	${NO_EXPORT_CPP:D:UCPP=${CPP:Q}}
MAKE_ENV+=	LINK_ALL_LIBGCC_HACK=${LINK_ALL_LIBGCC_HACK:Q}
MAKE_ENV+=	LOCALBASE=${LOCALBASE:Q}
MAKE_ENV+=	NO_WHOLE_ARCHIVE_FLAG=${NO_WHOLE_ARCHIVE_FLAG:Q}
MAKE_ENV+=	WHOLE_ARCHIVE_FLAG=${WHOLE_ARCHIVE_FLAG:Q}
MAKE_ENV+=	X11BASE=${X11BASE:Q}
MAKE_ENV+=	X11PREFIX=${X11PREFIX:Q}
MAKE_ENV+=	PKGMANDIR=${PKGMANDIR:Q}
MAKE_ENV+=	PKGINFODIR=${PKGINFODIR:Q}

# Provide a consistent environment for packages using (Net)BSD-style
# Makefiles.
#
MAKE_ENV+=	MAKECONF=${PKGMAKECONF:U/dev/null}
MAKE_ENV+=	OBJECT_FMT=${OBJECT_FMT:Q}
MAKE_ENV+=	${USETOOLS:DUSETOOLS=${USETOOLS:Q}}

# Add these bits to the environment used when invoking the recursive make
# processes for build-related phases.
#
PKGSRC_MAKE_ENV+=	PATH=${PATH:Q}
PKGSRC_MAKE_ENV+=	USE_DESTDIR=${USE_DESTDIR:Q}
