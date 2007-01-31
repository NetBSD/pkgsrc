# $NetBSD: Makefile,v 1.10 2007/01/31 00:04:12 wiz Exp $
#
.include "../../shells/ast-ksh/Makefile.common"

CONFLICTS=	ast-ksh-[0-9]*	# Override.

BROKEN_IN=		pkgsrc-2006Q4

DISTINFO_FILE=	${.CURDIR}/../../shells/ast-ksh/distinfo
PATCHDIR=	${.CURDIR}/../../shells/ast-ksh/patches
PKGDIR=		${.CURDIR}/../../shells/ast-ksh

PKGNAME:=	static-${PKGNAME}
COMMENT:=	Statically-linked version of the ${COMMENT}

KSH93_MAKEFLAGS=LDFLAGS=-static

.include "../../mk/bsd.pkg.mk"
