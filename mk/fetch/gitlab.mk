# $NetBSD: gitlab.mk,v 1.2 2022/05/24 13:05:37 nikita Exp $
#
# gitlab.com master site handling
#
# To use, set in Makefile:
#
# DISTNAME=	exampleproject-1.2
# MASTER_SITES=	${MASTER_SITE_GITLAB:=accountname/}
#
# The following variables alter gitlab.mk behavior:
#
# GITLAB_PROJECT	defaults to PKGBASE
# GITLAB_TAG		defaults to PKGVERSION_NOREV
#			sometimes you want to override with v${PKGVERSION_NOREV}
#			SHA-1 commit ids are also acceptable
# GITLAB_RELEASE	defaults to not defined, set this to ${DISTNAME}
#			when packaging a release not based on a git tag.
# GITLAB_SUBMODULES	manually set submodule information:
#			values should be:
#			GitLab_user GitLab_project tag_or_hash submodule_path
# GITLAB_TYPE		overrides the autodetected MASTER_SITE URL scheme:
#
# "tag"
# This is the default when GITLAB_RELEASE is not defined. Example URL:
# https://gitlab.com/acct/${GITLAB_PROJECT}/-/archive/${GITLAB_TAG}/${GITLAB_PROJECT}-${GITLAB_TAG}.tar.gz
#
# "release"
# This is the default when GITLAB_RELEASE is set. Example URL:
# https://gitlab.com/acct/${GITLAB_PROJECT}/-/archive/${GITLAB_RELEASE}/${DISTNAME}.tar.gz
#
# Keywords: gitlab

.if defined(MASTER_SITES) && !empty(MASTER_SITES:C,^https\://gitlab.com/[-a-zA-Z0-9_]*/$,match,:Mmatch)
_USE_GITLAB=		YES
.elif defined(MASTER_SITES) && !empty(MASTER_SITES:C,^https\://gitlab.com/[-a-zA-Z0-9_]*/[-a-zA-Z0-9_]*/$,match,:Mmatch)
_USE_GITLAB=		YES
.endif

.if (defined(GITLAB_TAG) || defined(GITLAB_RELEASE)) && !defined(_USE_GITLAB)
PKG_FAIL_REASON+=	"MASTER_SITES must match https://gitlab.com/account/"	\
			"when GITLAB_TAG or GITLAB_RELEASE is in use."		\
			"For more information: make help topic=gitlab"
.endif

.if defined(_USE_GITLAB) && !empty(_USE_GITLAB:M[yY][eE][sS])

GITLAB_PROJECT?=	${PKGBASE}
GITLAB_TAG?=		${PKGVERSION_NOREV}

.  if !empty(GITLAB_TAG:Mmaster)
PKG_FAIL_REASON+=	"master is not a valid tag name, use an explicit commit hash"
.  endif

.  if !defined(GITLAB_TYPE)
.    if defined(GITLAB_RELEASE) && !empty(GITLAB_RELEASE)
GITLAB_TYPE=	release
.    else
GITLAB_TYPE=	tag
.    endif
.  endif

.  if !empty(GITLAB_TYPE:Mtag) && !empty(GITLAB_TAG:M[a-f0-9][a-f0-9][a-f0-9][a-f0-9][a-f0-9][a-f0-9][a-f0-9]*)
# If the gitlab tag is a git hash (7 or more hex digits), encode it in the
# distfile name.
_GITLAB_DEFAULT_DISTFILES=	${DISTNAME}-${GITLAB_TAG}${EXTRACT_SUFX}
.  else
_GITLAB_DEFAULT_DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
.  endif

.  if !empty(GITLAB_TYPE:Mrelease)
SITES.${_GITLAB_DEFAULT_DISTFILES}=	${MASTER_SITES:=${GITLAB_PROJECT}/-/archive/${GITLAB_RELEASE}/}
.  endif

.  if !empty(GITLAB_TYPE:Mtag)
SITES.${_GITLAB_DEFAULT_DISTFILES}=	-${MASTER_SITES:=${GITLAB_PROJECT}/-/archive/${GITLAB_TAG}/${GITLAB_PROJECT}-${GITLAB_TAG}${EXTRACT_SUFX}}
.  endif

.endif

.if !empty(GITLAB_SUBMODULES)
.  for _GITLAB_SM_USER _GITLAB_SM_PROJECT _GITLAB_SM_TAG _GITLAB_SM_PLACE in ${GITLAB_SUBMODULES}
_GITLAB_SM_DISTFILE=			${_GITLAB_SM_USER}-${_GITLAB_SM_PROJECT}-${_GITLAB_SM_TAG}${EXTRACT_SUFX}
_GITLAB_DEFAULT_DISTFILES+=		${_GITLAB_SM_USER}-${_GITLAB_SM_PROJECT}-${_GITLAB_SM_TAG}${EXTRACT_SUFX}
SITES.${_GITLAB_SM_DISTFILE}=		-${MASTER_SITE_GITLAB:=${_GITLAB_SM_USER}/${_GITLAB_SM_PROJECT}/-/archive/${_GITLAB_SM_TAG}/${_GITLAB_SM_PROJECT}-${_GITLAB_SM_TAG}${EXTRACT_SUFX}}
EXTRACT_DIR.${_GITLAB_SM_DISTFILE}=	${WRKSRC}/${_GITLAB_SM_PLACE}
EXTRACT_OPTS_TAR.${_GITLAB_SM_DISTFILE}=	--strip-components=1
.  endfor
.endif

_VARGROUPS+=		gitlab
_PKG_VARS.gitlab=	GITLAB_PROJECT DISTNAME GITLAB_TYPE GITLAB_TAG \
			GITLAB_RELEASE MASTER_SITES EXTRACT_SUFX \
			GITLAB_SUBMODULES
_DEF_VARS.gitlab=	_USE_GITLAB _GITLAB_DEFAULT_DISTFILES
.for f in ${_GITLAB_DEFAULT_DISTFILES}
_DEF_VARS.gitlab+=	SITES.${f}
.endfor
_USE_VARS.gitlab=	PKGBASE PKGVERSION_NOREV
_LISTED_VARS.gitlab=	SITES.*
