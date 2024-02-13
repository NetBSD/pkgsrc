# $NetBSD: github.mk,v 1.19 2024/02/13 23:29:57 wiz Exp $
#
# github.com master site handling
#
# To use, set in Makefile:
#
# DISTNAME=	exampleproject-1.2
# MASTER_SITES=	${MASTER_SITE_GITHUB:=accountname/}
#
# The following variables alter github.mk behavior:
#
# GITHUB_PROJECT	defaults to PKGBASE
# GITHUB_TAG		defaults to PKGVERSION_NOREV
#			sometimes you want to override with v${PKGVERSION_NOREV}
#			SHA-1 commit ids are also acceptable
# GITHUB_RELEASE	defaults to not defined, set this to ${DISTNAME}
#			when packaging a release not based on a git tag.
# GITHUB_SUBMODULES	manually set submodule information:
#			values should be:
#			GitHub_user GitHub_project tag_or_hash submodule_path
# GITHUB_TYPE		overrides the autodetected MASTER_SITE URL scheme:
#
# "tag"
# This is the default when GITHUB_RELEASE is not defined. Example URL:
# http://github.com/acct/${GITHUB_PROJECT}/archive/{GITHUB_TAG}.tar.gz
#
# "release"
# This is the default when GITHUB_RELEASE is set. Example URL:
# http://github.com/acct/${GITHUB_PROJECT}/releases/download/${GITHUB_RELEASE}/${DISTNAME}.tar.gz
#
# Keywords: github

.if defined(MASTER_SITES) && !empty(MASTER_SITES:C,^https\://github.com/[-a-zA-Z0-9]*/$,match,:Mmatch)
_USE_GITHUB=		YES
.endif

.if (defined(GITHUB_TAG) || defined(GITHUB_RELEASE)) && !defined(_USE_GITHUB)
PKG_FAIL_REASON+=	"MASTER_SITES must match https://github.com/account/"	\
			"when GITHUB_TAG or GITHUB_RELEASE is in use."		\
			"For more information: make help topic=github"
.endif

.if defined(_USE_GITHUB) && !empty(_USE_GITHUB:M[yY][eE][sS])

GITHUB_PROJECT?=	${PKGBASE}
GITHUB_TAG?=		${PKGVERSION_NOREV}

.  if !empty(GITHUB_TAG:Mmaster) || !empty(GITHUB_TAG:Mmain)
PKG_FAIL_REASON+=	"main (or master) is not a valid tag name; use an explicit commit hash or a tag, not a branch"
.  endif

.  if !defined(GITHUB_TYPE)
.    if defined(GITHUB_RELEASE) && !empty(GITHUB_RELEASE)
GITHUB_TYPE=	release
.    else
GITHUB_TYPE=	tag
.    endif
.  endif

.  if !empty(GITHUB_TYPE:Mtag) && !empty(GITHUB_TAG:M[a-f0-9][a-f0-9][a-f0-9][a-f0-9][a-f0-9][a-f0-9][a-f0-9]*)
# If the github tag is a git hash (7 or more hex digits), encode it in the
# distfile name.
_GITHUB_DEFAULT_DISTFILES=	${DISTNAME}-${GITHUB_TAG}${EXTRACT_SUFX}
.  else
_GITHUB_DEFAULT_DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
.  endif

.  if !empty(GITHUB_TYPE:Mrelease)
SITES.${_GITHUB_DEFAULT_DISTFILES}=	${MASTER_SITES:=${GITHUB_PROJECT}/releases/download/${GITHUB_RELEASE}/}
.  endif

.  if !empty(GITHUB_TYPE:Mtag)
SITES.${_GITHUB_DEFAULT_DISTFILES}=	-${MASTER_SITES:=${GITHUB_PROJECT}/archive/${GITHUB_TAG}${EXTRACT_SUFX}}
.  endif

.endif

.for user project tag place in ${GITHUB_SUBMODULES}
.  for distfile in ${user}-${project}-${tag}${EXTRACT_SUFX}
_GITHUB_DEFAULT_DISTFILES+=	${distfile}
SITES.${distfile}=		-${MASTER_SITE_GITHUB:=${user}/${project}/archive/${tag}${EXTRACT_SUFX}}
EXTRACT_DIR.${distfile}=	${WRKSRC}/${place}
EXTRACT_OPTS_TAR.${distfile}=	--strip-components=1
.  endfor
.endfor

_VARGROUPS+=		github
_PKG_VARS.github=	GITHUB_PROJECT DISTNAME GITHUB_TYPE GITHUB_TAG \
			GITHUB_RELEASE MASTER_SITES EXTRACT_SUFX \
			GITHUB_SUBMODULES
_DEF_VARS.github=	_USE_GITHUB _GITHUB_DEFAULT_DISTFILES
.for f in ${_GITHUB_DEFAULT_DISTFILES}
_DEF_VARS.github+=	SITES.${f}
.endfor
_USE_VARS.github=	PKGBASE PKGVERSION_NOREV
_LISTED_VARS.github=	SITES.*
