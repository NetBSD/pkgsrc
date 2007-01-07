# $NetBSD: Makefile,v 1.20 2007/01/07 09:14:00 rillig Exp $

DISTNAME=		9menu-1.8
PKGREVISION=		1
CATEGORIES=		misc plan9
MASTER_SITES=		ftp://ftp.freefriends.org/arnold/Source/
EXTRACT_SUFX=		.shar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Simple menu patterned after the plan9 user interface

MAKE_FILE=		Makefile.noimake
BUILD_TARGET=		9menu

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/x11.buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/9menu ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/9menu.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
