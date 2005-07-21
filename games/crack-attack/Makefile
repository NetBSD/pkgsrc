# $NetBSD: Makefile,v 1.8 2005/07/21 16:29:50 wiz Exp $

DISTNAME=	crack-attack-1.1.14
CATEGORIES=	games
MASTER_SITES=	http://savannah.nongnu.org/download/crack-attack/

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/crack-attack
COMMENT=	Tetris Attack inspired game

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/html/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/*.jpg ${PREFIX}/share/doc/html/${PKGBASE}

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
