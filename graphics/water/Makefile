# $NetBSD: Makefile,v 1.8 2004/04/12 02:28:00 snj Exp $
#

DISTNAME=	water-1.0
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/water/src/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/water/
COMMENT=	Motion in a pool of water

USE_BUILDLINK3=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/water
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/water
	${INSTALL_DATA} ${WRKSRC}/water320.bmp ${PREFIX}/share/water
	${INSTALL_DATA} ${WRKSRC}/water.txt ${PREFIX}/share/doc/water

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
