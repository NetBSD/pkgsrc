# $NetBSD: Makefile,v 1.1 2004/01/10 06:53:45 grant Exp $
#

DISTINFO_FILE=		${.CURDIR}/../../shells/tcsh/distinfo
PATCHDIR=		${.CURDIR}/../../shells/tcsh/patches
PKGDIR=			${.CURDIR}/../../shells/tcsh

CONFLICTS=		tcsh-[0-9]*
CONFLICTS+=		static-tcsh-[0-9]*

.include "../../shells/tcsh/Makefile"

WRKSRC:=		${WRKDIR}/${DISTNAME}
PKGNAME:=		${DISTNAME:C|-.*||}-static${DISTNAME:C|[^-]*||}
COMMENT:=		Statically-linked version of the ${COMMENT}

LDFLAGS+=		-static
