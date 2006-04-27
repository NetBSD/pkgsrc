# $NetBSD: Makefile,v 1.9 2006/04/27 15:32:14 hubertf Exp $
#
.include "../../shells/ast-ksh/Makefile.common"

CONFLICTS=	ast-ksh-[0-9]*	# Override.

DISTINFO_FILE=	${.CURDIR}/../../shells/ast-ksh/distinfo
PATCHDIR=	${.CURDIR}/../../shells/ast-ksh/patches
PKGDIR=		${.CURDIR}/../../shells/ast-ksh

PKGNAME:=	static-${PKGNAME}
COMMENT:=	Statically-linked version of the ${COMMENT}

KSH93_MAKEFLAGS=LDFLAGS=-static

.include "../../mk/bsd.pkg.mk"
