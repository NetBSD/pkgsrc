# $NetBSD: Makefile,v 1.5 2004/01/11 23:06:54 grant Exp $
#

DISTINFO_FILE=		${.CURDIR}/../../shells/tcsh/distinfo
PATCHDIR=		${.CURDIR}/../../shells/tcsh/patches
PKGDIR=			${.CURDIR}/../../shells/tcsh

CONFLICTS=		tcsh-[0-9]*

.include "../../shells/tcsh/Makefile"

WRKSRC:=		${WRKDIR}/${DISTNAME}
PKGNAME:=		static-${DISTNAME}
COMMENT:=		Statically-linked version of the ${COMMENT}

LDFLAGS+=		-static
