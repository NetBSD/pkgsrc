# $NetBSD: Makefile,v 1.1.1.1 2002/09/27 22:09:09 cjep Exp $
#

DISTINFO_FILE=		${.CURDIR}/../../shells/bash2/distinfo
PATCHDIR=		${.CURDIR}/../../shells/bash2/patches
PKGDIR=			${.CURDIR}/../../shells/bash2

CONFLICTS=		bash-[0-9]*

.include "../../shells/bash2/Makefile"

WRKSRC:=		${WRKDIR}/${DISTNAME}
PKGNAME:=		static-${PKGNAME}
COMMENT:=		Statically-linked version of the ${COMMENT}

LDFLAGS+=		-static
