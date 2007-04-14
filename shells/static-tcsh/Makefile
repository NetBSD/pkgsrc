# $NetBSD: Makefile,v 1.6 2007/04/14 11:43:13 wiz Exp $
#

MAINTAINER=		agc@NetBSD.org

DISTINFO_FILE=		${.CURDIR}/../../shells/tcsh/distinfo
PATCHDIR=		${.CURDIR}/../../shells/tcsh/patches
PKGDIR=			${.CURDIR}/../../shells/tcsh

CONFLICTS=		tcsh-[0-9]*

.include "../../shells/tcsh/Makefile"

WRKSRC:=		${WRKDIR}/${DISTNAME}
PKGNAME:=		static-${DISTNAME}
COMMENT:=		Statically-linked version of the ${COMMENT}

LDFLAGS+=		-static
