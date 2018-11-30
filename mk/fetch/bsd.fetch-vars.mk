# $NetBSD: bsd.fetch-vars.mk,v 1.23 2018/11/30 18:38:20 rillig Exp $
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
#    POST_FETCH_HOOK is a program to execute after fetch successfully
#	obtained a file.  It is called with the relative path of the distfile
#	in ${DISTDIR} and the full URL it was obtained from.
#
#    IGNORE_INTERACTIVE_FETCH can be set to yes to skip the normal
#	interactive check logic and tries any provided MASTER_SITE
#	or MASTER_SITE_OVERRIDE.
#
#	The normal backup sites are explicitly disabled in this case.
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
_LISTED_VARS.fetch=	*S

# The default DISTDIR is currently set in bsd.prefs.mk.
#DISTDIR?=               ${PKGSRCDIR}/distfiles

_DISTDIR=		${DISTDIR}/${DIST_SUBDIR}
.if defined(DISTNAME) && !empty(DISTNAME)
.  if defined(GITHUB_TAG) && !empty(GITHUB_TAG:M[a-f0-9][a-f0-9][a-f0-9][a-f0-9][a-f0-9][a-f0-9][a-f0-9]*)
# If the github tag is a git hash (7 or more hex digits), encode it in the
# distfile name. It would be better to use ${_GITHUB_DEFAULT_DISTFILES} here,
# but that gets assigned much later.
DEFAULT_DISTFILES=	${DISTNAME}-${GITHUB_TAG}${EXTRACT_SUFX}
.  else
DEFAULT_DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
.  endif
.endif
DISTFILES?=		${DEFAULT_DISTFILES}

# File lists, defined early to allow tool dependencies.
ALLFILES?=	${DISTFILES} ${PATCHFILES}
ALLFILES:=	${ALLFILES:O:u}		# remove duplicates
CKSUMFILES?=	${ALLFILES}
.for __tmp__ in ${IGNOREFILES}
CKSUMFILES:=	${CKSUMFILES:N${__tmp__}}
.endfor

# List of all files, with ${DIST_SUBDIR} in front.  Used for fetch and checksum.
.if defined(DIST_SUBDIR) && !empty(DIST_SUBDIR)
_CKSUMFILES?=	${CKSUMFILES:@.f.@${DIST_SUBDIR}/${.f.}@}
_DISTFILES?=	${DISTFILES:@.f.@${DIST_SUBDIR}/${.f.}@}
_IGNOREFILES?=	${IGNOREFILES:@.f.@${DIST_SUBDIR}/${.f.}@}
_PATCHFILES?=	${PATCHFILES:@.f.@${DIST_SUBDIR}/${.f.}@}
.else
_CKSUMFILES?=	${CKSUMFILES}
_DISTFILES?=	${DISTFILES}
_IGNOREFILES?=	${IGNOREFILES}
_PATCHFILES?=	${PATCHFILES}
.endif
_ALLFILES?=	${_DISTFILES} ${_PATCHFILES}
_ALLFILES:=	${_ALLFILES:O:u}	# remove duplicates

_BUILD_DEFS+=	_DISTFILES _PATCHFILES

# When mirroring distfiles which others may fetch, only fetch the
# distfiles if it is allowed to be re-distributed freely.  Also,
# suppress some bootstrap-depends output.
#
.if make(mirror-distfiles)
NO_SKIP=		# defined
_BOOTSTRAP_VERBOSE=	# defined
.endif

.if !empty(_CKSUMFILES) && defined(FAILOVER_FETCH)
USE_TOOLS+=	digest:bootstrap
.endif

_FETCH_TOOLS.ftp=		ftp
_FETCH_TOOLS.fetch=		fetch
_FETCH_TOOLS.wget=		wget
_FETCH_TOOLS.curl=		curl
_FETCH_TOOLS.manual=		false

.if !empty(_ALLFILES)
USE_TOOLS+=	${_FETCH_TOOLS.${FETCH_USING}:C/$/:bootstrap/}
BOOTSTRAP_DEPENDS+=	${_FETCH_DEPENDS.${FETCH_USING}}
.endif
