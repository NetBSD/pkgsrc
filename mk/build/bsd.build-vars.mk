# $NetBSD: bsd.build-vars.mk,v 1.14 2020/09/12 06:51:15 rillig Exp $
#
# Package-settable variables:
#
# BUILD_DIRS
#	The directories in which to perform the build process.
#	Relative paths are relative to ${WRKSRC}.
#
# MAKE_ENV
#	The shell environment that is exported to the make process.
#
# MAKE_FLAGS
#	The flags that are passed to the make commands during the build
#	(the "inner" make when building the package itself, not the
#	"outer" make on the pkgsrc level).
#
#	Typical flags are -s for silent mode (works for GNU make as
#	well as for bmake), or variable assignments that override
#	anything specified in the Makefile, such as CFLAGS=-O0.
#
# MAKE_FILE
#	The path to the makefile that is processed by the make executable.
#	Relative paths are relative to each of the directories from
#	BUILD_DIRS.
#
# System-provided variables:
#
# MAKE_PROGRAM
#	The path to the make executable that is run to process the source
#	makefiles. See mk/tools/make.mk.
#
# See also:
#	https://www.netbsd.org/docs/pkgsrc/pkgsrc.html#build.build
#

_VARGROUPS+=		build-vars
_USER_VARS.build-vars=	# none
_PKG_VARS.build-vars=	BUILD_DIRS MAKE_ENV MAKE_PROGRAM MAKE_FLAGS MAKE_FILE NO_BUILD
_LISTED_VARS.build-vars=	BUILD_DIRS
_SORTED_VARS.build-vars=	MAKE_ENV MAKE_FLAGS

BUILD_DIRS?=	${CONFIGURE_DIRS}
MAKE_ENV?=	# empty
MAKE_FLAGS?=	# empty
MAKE_FILE?=	Makefile

MAKE_ENV+=	${ALL_ENV}
MAKE_ENV+=	${NO_EXPORT_CPP:D:UCPP=${CPP:Q}}
MAKE_ENV+=	LOCALBASE=${LOCALBASE:Q}
MAKE_ENV+=	X11BASE=${X11BASE:Q}
MAKE_ENV+=	PKGMANDIR=${PKGMANDIR:Q}
MAKE_ENV+=	PKGINFODIR=${PKGINFODIR:Q}
MAKE_ENV+=	PKGGNUDIR=${PKGGNUDIR:Q}

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
