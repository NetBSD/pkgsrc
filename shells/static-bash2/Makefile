# $NetBSD: Makefile,v 1.4 2004/01/11 23:06:54 grant Exp $
#

DISTINFO_FILE=		${.CURDIR}/../../shells/bash2/distinfo
PATCHDIR=		${.CURDIR}/../../shells/bash2/patches
PKGDIR=			${.CURDIR}/../../shells/bash2

CONFLICTS=		bash-[0-9]*

.include "../../shells/bash2/Makefile"

WRKSRC:=		${WRKDIR}/${DISTNAME}
PKGNAME:=		static-${DISTNAME}
COMMENT:=		Statically-linked version of the ${COMMENT}

LDFLAGS+=		-static
