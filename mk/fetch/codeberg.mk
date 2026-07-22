# $NetBSD: codeberg.mk,v 1.1 2026/07/22 15:06:51 ryoon Exp $
#
# codeberg.org master site handling
#
# To use, set in Makefile:
#
# DISTNAME=	exampleproject-1.2
# MASTER_SITES=	${MASTER_SITE_CODEBERG:=accountname/}
#
# The following variables alter codeberg.mk behavior:
#
# CODEBERG_PROJECT	defaults to PKGBASE
# CODEBERG_TAG		defaults to PKGVERSION_NOREV
#			sometimes you want to override with v${PKGVERSION_NOREV}
#			SHA-1 commit ids are also acceptable
# CODEBERG_RELEASE	defaults to not defined, set this to ${DISTNAME}
#			when packaging a release not based on a git tag.
# CODEBERG_SUBMODULES	manually set submodule information:
#			values should be:
#			Codeberg_user Codeberg_project tag_or_hash submodule_path
# CODEBERG_TYPE		overrides the autodetected MASTER_SITE URL scheme:
#
# "tag"
# This is the default when CODEBERG_RELEASE is not defined. Example URL:
# http://codeberg.org/acct/${CODEBERG_PROJECT}/archive/{CODEBERG_TAG}.tar.gz
#
# "release"
# This is the default when CODEBERG_RELEASE is set. Example URL:
# http://codeberg.org/acct/${CODEBERG_PROJECT}/releases/download/${CODEBERG_RELEASE}/${DISTNAME}.tar.gz
#
# Keywords: codeberg

.if defined(MASTER_SITES) && !empty(MASTER_SITES:C,^https\://codeberg.org/[-a-zA-Z0-9]*/$,match,:Mmatch)
_USE_CODEBERG=		YES
.endif

.if (defined(CODEBERG_TAG) || defined(CODEBERG_RELEASE)) && !defined(_USE_CODEBERG)
PKG_FAIL_REASON+=	"MASTER_SITES must match https://codeberg.org/account/"	\
			"when CODEBERG_TAG or CODEBERG_RELEASE is in use."		\
			"For more information: make help topic=codeberg"
.endif

.if defined(_USE_CODEBERG) && !empty(_USE_CODEBERG:M[yY][eE][sS])

CODEBERG_PROJECT?=	${PKGBASE}
CODEBERG_TAG?=		${PKGVERSION_NOREV}

.  if !empty(CODEBERG_TAG:Mmaster) || !empty(CODEBERG_TAG:Mmain)
PKG_FAIL_REASON+=	"main (or master) is not a valid tag name; use an explicit commit hash or a tag, not a branch"
.  endif

.  if !defined(CODEBERG_TYPE)
.    if defined(CODEBERG_RELEASE) && !empty(CODEBERG_RELEASE)
CODEBERG_TYPE=	release
.    else
CODEBERG_TYPE=	tag
.    endif
.  endif

.  if !empty(CODEBERG_TYPE:Mtag) && !empty(CODEBERG_TAG:M[a-f0-9][a-f0-9][a-f0-9][a-f0-9][a-f0-9][a-f0-9][a-f0-9]*)
# If the codeberg tag is a git hash (7 or more hex digits), encode it in the
# distfile name.
_CODEBERG_DEFAULT_DISTFILES=	${DISTNAME}-${CODEBERG_TAG}${EXTRACT_SUFX}
.  else
_CODEBERG_DEFAULT_DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
.  endif

.  if !empty(CODEBERG_TYPE:Mrelease)
SITES.${_CODEBERG_DEFAULT_DISTFILES}=	${MASTER_SITES:=${CODEBERG_PROJECT}/releases/download/${CODEBERG_RELEASE}/}
.  endif

.  if !empty(CODEBERG_TYPE:Mtag)
SITES.${_CODEBERG_DEFAULT_DISTFILES}=	-${MASTER_SITES:=${CODEBERG_PROJECT}/archive/${CODEBERG_TAG}${EXTRACT_SUFX}}
.  endif

.endif

.for user project tag place in ${CODEBERG_SUBMODULES}
.  for distfile in ${user}-${project}-${tag}${EXTRACT_SUFX}
_CODEBERG_DEFAULT_DISTFILES+=	${distfile}
SITES.${distfile}=		-${MASTER_SITE_CODEBERG:=${user}/${project}/archive/${tag}${EXTRACT_SUFX}}
EXTRACT_DIR.${distfile}=	${WRKSRC}/${place}
EXTRACT_OPTS_TAR.${distfile}=	--strip-components=1
.  endfor
.endfor

_VARGROUPS+=		codeberg
_PKG_VARS.codeberg=	CODEBERG_PROJECT DISTNAME CODEBERG_TYPE CODEBERG_TAG \
			CODEBERG_RELEASE MASTER_SITES EXTRACT_SUFX \
			CODEBERG_SUBMODULES
_DEF_VARS.codeberg=	_USE_CODEBERG _CODEBERG_DEFAULT_DISTFILES
.for f in ${_CODEBERG_DEFAULT_DISTFILES}
_DEF_VARS.codeberg+=	SITES.${f}
.endfor
_USE_VARS.codeberg=	PKGBASE PKGVERSION_NOREV
_LISTED_VARS.codeberg=	SITES.*
