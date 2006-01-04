# $NetBSD: Makefile,v 1.7 2006/01/04 04:29:08 schmonz Exp $
#
.include "../../shells/ast-ksh/Makefile.common"

PKGREVISION=	1

BROKEN_IN=	pkgsrc-2005Q4

CONFLICTS=	ast-ksh-[0-9]*	# Override.

DISTINFO_FILE=	${.CURDIR}/../../shells/ast-ksh/distinfo
PATCHDIR=	${.CURDIR}/../../shells/ast-ksh/patches
PKGDIR=		${.CURDIR}/../../shells/ast-ksh

PKGNAME:=	static-${PKGNAME}
COMMENT:=	Statically-linked version of the ${COMMENT}

KSH93_MAKEFLAGS=LDFLAGS=-static

.include "../../mk/bsd.pkg.mk"
