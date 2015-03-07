# $NetBSD: github.mk,v 1.2 2015/03/07 15:31:52 tnn Exp $
#
# github.com master site handling
#
# To use, set in Makefile:
#
# DISTNAME=	exampleproject-1.2
# USE_GITHUB=	YES
#
# The following variables alter USE_GITHUB behavior:
#
# GH_ACCOUNT	defaults to PKGBASE
# GH_PROJECT	defaults to PKGBASE
# GH_TAGNAME	defaults to PKGVERSION_NOREV
#		(sometimes you want to override with v${PKGVERSION_NOREV})
# GH_COMMIT	explicit commit hash if no tag is available
# GH_RELEASE	default empty, may be set to ${DISTNAME} for example
# GH_TYPE	overrides the autodetected MASTER_SITE URL scheme:
#
# "tag"
# This is the default when GH_TAGNAME is set. Exampe URL:
# http://www.github.com/acct/proj/archive/{GH_TAGNAME}.tar.gz
#
# "release"
# This is the default when GH_RELEASE is set. Example URL:
# http://www.github.com/acct/proj/releases/download/${GH_RELEASE}/${DISTNAME}${EXTRACT_SUFX}
#
# "commit"
# This is the default when GH_TAGNAME and GH_COMMIT are empty.
# -${MASTER_SITE_GITHUB}${GH_ACCOUNT}/{GH_PROJECT}/releases/download/${PKGVERSION_NOREV}${EXTRACT_SUFX}
#
# Keywords: github


.if defined(USE_GITHUB) && !empty(USE_GITHUB:M[yY][eE][sS])

# maybe move this to sites.mk
MASTER_SITE_GITHUB?=		http://github.com/

GH_ACCOUNT?=	${PKGBASE}
GH_PROJECT?=	${PKGBASE}
GH_TAGNAME?=	${PKGVERSION_NOREV}

.  if !empty(GH_TAGNAME:Mmaster)
PKG_FAIL_REASON+=	"master is not a valid tag name, use an explicit commit hash (hint: set GH_COMMIT)"
.  endif

.  if !defined(GH_TYPE)
.    if defined(GH_COMMIT) && !empty(GH_COMMIT:M*)
GH_TYPE=	commit
.  elif defined(GH_RELEASE) && !empty(GH_RELEASE:M*)
GH_TYPE=	release
.  else
GH_TYPE=	tag
.    endif
.  endif

.if !empty(GH_TYPE:Mrelease)
MASTER_SITES?=	${MASTER_SITE_GITHUB}${GH_ACCOUNT}/${GH_PROJECT}/releases/download/${GH_RELEASE}/
.endif

.if !empty(GH_TYPE:Mcommit)
MASTER_SITES?=	-${MASTER_SITE_GITHUB}${GH_ACCOUNT}/${GH_PROJECT}/archive/${GH_COMMIT}${EXTRACT_SUFX}
.endif

.if !empty(GH_TYPE:Mtag)
MASTER_SITES?=	-${MASTER_SITE_GITHUB}${GH_ACCOUNT}/${GH_PROJECT}/archive/${GH_TAGNAME}${EXTRACT_SUFX}
.endif

.endif
