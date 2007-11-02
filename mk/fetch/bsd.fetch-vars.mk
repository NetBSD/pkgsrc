# $NetBSD: bsd.fetch-vars.mk,v 1.9 2007/11/02 09:02:57 rillig Exp $
#
# This Makefile fragment is included separately by bsd.pkg.mk and
# defines some variables which must be defined earlier than where
# bsd.fetch.mk is included.
#
# The following variables may be set by the user:
#
#    DISTDIR is the top-level directory into which all original
#	distribution files are fetched.
#
#    DIST_PATH is a list of directories, separated by colons, in which
#	the distribution files are looked up, additionally to DISTDIR.
#	No files will ever be created in these directories.
#
# The following variables may be set in a package Makefile:
#
#    DIST_SUBDIR is the subdirectory of ${DISTDIR} in which the original
#	distribution files for the package are fetched.
#
#    DISTFILES is the list of distribution files that are fetched.
#
# System-provided variables:
#
# DEFAULT_DISTFILES
#	The default value for DISTFILES. This can be used when you need
#	more than the usual distfiles.
#

_VARGROUPS+=		fetch
_USER_VARS.fetch=	DISTDIR DIST_PATH
_PKG_VARS.fetch=	MASTER_SITES DIST_SUBDIR DISTFILES
_SYS_VARS.fetch=	DEFAULT_DISTFILES

# The default DISTDIR is currently set in bsd.prefs.mk.
#DISTDIR?=               ${PKGSRCDIR}/distfiles

_DISTDIR=		${DISTDIR}/${DIST_SUBDIR}
DEFAULT_DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES?=		${DEFAULT_DISTFILES}

# "Failover" fetching requires the digest tool to compute checksums to
# verify any fetched files.  But if no checksumming is requested, don't
# add it.
#
.if defined(FAILOVER_FETCH) && !defined(NO_CHECKSUM)
USE_TOOLS+=		${FAILOVER_FETCH:Ddigest\:bootstrap}
.endif

# When mirroring distfiles which others may fetch, only fetch the
# distfiles if it is allowed to be re-distributed freely.  Also,
# suppress some bootstrap-depends output.
#
.if make(mirror-distfiles)
NO_SKIP=		# defined
_BOOTSTRAP_VERBOSE=	# defined
.endif
