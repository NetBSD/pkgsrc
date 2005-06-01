# $NetBSD: Makefile,v 1.15 2005/06/01 18:03:04 jlam Exp $

DISTNAME=		9menu-1.8
CATEGORIES=		misc plan9
MASTER_SITES=		ftp://ftp.freefriends.org/arnold/Source/
EXTRACT_SUFX=		.shar.gz

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Simple menu patterned after the plan9 user interface

MAKEFILE=		Makefile.noimake
BUILD_TARGET=		9menu

WRKSRC=			${WRKDIR}

.include "../../mk/x11.buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/9menu ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/9menu.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
