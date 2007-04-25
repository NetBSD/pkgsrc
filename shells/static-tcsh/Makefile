# $NetBSD: Makefile,v 1.7 2007/04/25 13:26:42 obache Exp $
#

MAINTAINER=		agc@NetBSD.org

DISTINFO_FILE=		${.CURDIR}/../../shells/tcsh/distinfo
PATCHDIR=		${.CURDIR}/../../shells/tcsh/patches
PKGDIR=			${.CURDIR}/../../shells/tcsh

CONFLICTS=		tcsh-[0-9]*

PKGNAME=		static-${DISTNAME}

.include "../../shells/tcsh/Makefile"

COMMENT:=		Statically-linked version of the ${COMMENT}

LDFLAGS+=		-static
