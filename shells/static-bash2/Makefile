# $NetBSD: Makefile,v 1.6 2006/02/05 23:10:48 joerg Exp $
#

PKGREVISION=		1
DISTINFO_FILE=		${.CURDIR}/../../shells/bash2/distinfo
PATCHDIR=		${.CURDIR}/../../shells/bash2/patches
PKGDIR=			${.CURDIR}/../../shells/bash2

CONFLICTS=		bash-[0-9]*

.include "../../shells/bash2/Makefile"

WRKSRC:=		${WRKDIR}/${DISTNAME}
PKGNAME:=		static-${PKGNAME}
COMMENT:=		Statically-linked version of the ${COMMENT}

LDFLAGS+=		-static
