# $NetBSD: Makefile,v 1.8 2012/07/21 15:56:42 dholland Exp $
#

MAINTAINER=		agc@NetBSD.org

DISTINFO_FILE=		${.CURDIR}/../../shells/tcsh/distinfo
PATCHDIR=		${.CURDIR}/../../shells/tcsh/patches
PKGDIR=			${.CURDIR}/../../shells/tcsh
DESCR_SRC=		${.CURDIR}/../../shells/tcsh/DESCR ${.CURDIR}/DESCR

CONFLICTS=		tcsh-[0-9]*

PKGNAME=		static-${DISTNAME}

.include "../../shells/tcsh/Makefile"

COMMENT:=		Statically-linked version of the ${COMMENT}

LDFLAGS+=		-static
