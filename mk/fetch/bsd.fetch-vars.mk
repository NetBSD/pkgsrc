# $NetBSD: bsd.fetch-vars.mk,v 1.27 2024/05/13 08:09:30 wiz Exp $
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
_PKG_VARS.fetch=	MASTER_SITES DIST_SUBDIR DISTFILES \
			${DISTFILES:@distfile@SITES.${distfile}@}
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
.  elif defined(GITLAB_TAG) && !empty(GITLAB_TAG:M[a-f0-9][a-f0-9][a-f0-9][a-f0-9][a-f0-9][a-f0-9][a-f0-9]*)
# If the gitlab tag is a git hash (7 or more hex digits), encode it in the
# distfile name. It would be better to use ${_GITLAB_DEFAULT_DISTFILES} here,
# but that gets assigned much later.
DEFAULT_DISTFILES=	${DISTNAME}-${GITLAB_TAG}${EXTRACT_SUFX}
.  else
DEFAULT_DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
.  endif
.endif
DISTFILES?=		${DEFAULT_DISTFILES}

.if !empty(GITHUB_SUBMODULES)
.  for _GITHUB_SM_USER _GITHUB_SM_PROJECT _GITHUB_SM_TAG _GITHUB_SM_PLACE in ${GITHUB_SUBMODULES}
DISTFILES+=			${_GITHUB_SM_USER}-${_GITHUB_SM_PROJECT}-${_GITHUB_SM_TAG}${EXTRACT_SUFX}
.  endfor
.endif

.if !empty(GITLAB_SUBMODULES)
.  for _GITLAB_SM_USER _GITLAB_SM_PROJECT _GITLAB_SM_TAG _GITLAB_SM_PLACE in ${GITLAB_SUBMODULES}
DISTFILES+=			${_GITLAB_SM_USER}-${_GITLAB_SM_PROJECT}-${_GITLAB_SM_TAG}${EXTRACT_SUFX}
.  endfor
.endif

# File lists, defined early to allow tool dependencies.
ALLFILES?=	${DISTFILES} ${PATCHFILES}
ALLFILES:=	${ALLFILES:O:u}		# remove duplicates
CKSUMFILES?=	${ALLFILES}

# List of all files, with ${DIST_SUBDIR} in front.  Used for fetch and checksum.
.if defined(DIST_SUBDIR) && !empty(DIST_SUBDIR)
_CKSUMFILES?=	${CKSUMFILES:@.f.@${DIST_SUBDIR}/${.f.}@}
_DISTFILES?=	${DISTFILES:@.f.@${DIST_SUBDIR}/${.f.}@}
_PATCHFILES?=	${PATCHFILES:@.f.@${DIST_SUBDIR}/${.f.}@}
.else
_CKSUMFILES?=	${CKSUMFILES}
_DISTFILES?=	${DISTFILES}
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
