# $NetBSD: Makefile,v 1.3 2001/11/26 09:54:52 abs Exp $
#

DISTNAME=	water-1.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/water/src/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.libsdl.org/projects/water/
COMMENT=	Motion in a pool of water

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/water
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/water
	${INSTALL_DATA} ${WRKSRC}/water320.bmp ${PREFIX}/share/water
	${INSTALL_DATA} ${WRKSRC}/water.txt ${PREFIX}/share/doc/water

.include "../../devel/SDL/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
