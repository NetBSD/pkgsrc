# $NetBSD: Makefile,v 1.16 2020/04/17 21:28:01 ad Exp $
#

.include "../../shells/ast-ksh/Makefile.common"

PKGREVISION=	1
CONFLICTS=	ast-ksh-[0-9]*	# Override.

DISTINFO_FILE=	${.CURDIR}/../../shells/ast-ksh/distinfo
PATCHDIR=	${.CURDIR}/../../shells/ast-ksh/patches
PLIST_SRC=	${.CURDIR}/../../shells/ast-ksh/PLIST
DESCR_SRC?=	${.CURDIR}/../../shells/ast-ksh/DESCR

PKGNAME:=	static-${PKGNAME}
COMMENT:=	Statically-linked version of the ${COMMENT}

# SunOS 5.10 stopped shipping static libraries
NOT_FOR_PLATFORM+=	SunOS-5.1[0-9]-*

KSH93_MAKEFLAGS+=	LDFLAGS=-static

.include "../../mk/bsd.pkg.mk"
