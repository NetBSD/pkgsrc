# $NetBSD: Makefile,v 1.2 2002/09/30 07:59:32 martti Exp $
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
