# $NetBSD: Makefile,v 1.3 2002/07/25 11:05:02 kim Exp $
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
