# $NetBSD: Makefile,v 1.1 2004/01/10 07:06:44 grant Exp $
#

DISTINFO_FILE=		${.CURDIR}/../../shells/bash2/distinfo
PATCHDIR=		${.CURDIR}/../../shells/bash2/patches
PKGDIR=			${.CURDIR}/../../shells/bash2

CONFLICTS=		bash-[0-9]*
CONFLICTS+=		static-bash-[0-9]*

.include "../../shells/bash2/Makefile"

WRKSRC:=		${WRKDIR}/${DISTNAME}
PKGNAME:=		${PKGBASE}-static-${PKGVERSION}
COMMENT:=		Statically-linked version of the ${COMMENT}

LDFLAGS+=		-static
