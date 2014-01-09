# $NetBSD: Makefile,v 1.13 2014/01/09 12:24:41 jperkin Exp $
#

.include "../../shells/ast-ksh/Makefile.common"

CONFLICTS=	ast-ksh-[0-9]*	# Override.

DISTINFO_FILE=	${.CURDIR}/../../shells/ast-ksh/distinfo
PATCHDIR=	${.CURDIR}/../../shells/ast-ksh/patches
PKGDIR=		${.CURDIR}/../../shells/ast-ksh

PKGNAME:=	static-${PKGNAME}
COMMENT:=	Statically-linked version of the ${COMMENT}

# SunOS 5.10 stopped shipping static libraries
NOT_FOR_PLATFORM+=	SunOS-5.1[0-9]-*

KSH93_MAKEFLAGS=LDFLAGS=-static

.include "../../mk/bsd.pkg.mk"
