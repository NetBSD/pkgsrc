# $NetBSD: Makefile,v 1.1 2003/05/31 16:14:47 uebayasi Exp $
#
.include "../../shells/ast-ksh/Makefile.common"

CONFLICTS=	ast-ksh-[0-9]*	# Override.

DISTINFO_FILE=	${.CURDIR}/../../shells/ast-ksh/distinfo
PATCHDIR=	${.CURDIR}/../../shells/ast-ksh/patches
PKGDIR=		${.CURDIR}/../../shells/ast-ksh

PKGNAME:=	static-${PKGNAME}
COMMENT:=	Statically-linked version of the ${COMMENT}

KSH93_MAKEFLAGS=LDFLAGS=-static

.include "../../shells/ast-ksh/Makefile.include"
