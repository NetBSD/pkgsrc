# $NetBSD: Makefile,v 1.21 2007/02/02 17:07:48 joerg Exp $

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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/9menu ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/9menu.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
