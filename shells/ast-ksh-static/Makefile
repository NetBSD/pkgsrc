# $NetBSD: Makefile,v 1.1 2004/01/10 07:04:02 grant Exp $
#
.include "../../shells/ast-ksh/Makefile.common"

CONFLICTS=	ast-ksh-[0-9]*	# Override.
CONFLICTS+=	static-ast-ksh-[0-9]*

DISTINFO_FILE=	${.CURDIR}/../../shells/ast-ksh/distinfo
PATCHDIR=	${.CURDIR}/../../shells/ast-ksh/patches
PKGDIR=		${.CURDIR}/../../shells/ast-ksh

PKGVERSION:=	${PKGNAME:C|^.*-||}
PKGNAME:=	ast-ksh-static-${PKGVERSION}
COMMENT:=	Statically-linked version of the ${COMMENT}

KSH93_MAKEFLAGS=LDFLAGS=-static

.include "../../mk/bsd.pkg.mk"
