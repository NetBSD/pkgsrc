# $NetBSD: Makefile,v 1.5 2003/05/02 11:55:31 wiz Exp $
#

DISTNAME=	water-1.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/water/src/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.libsdl.org/projects/water/
COMMENT=	Motion in a pool of water

USE_BUILDLINK2=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/water
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/water
	${INSTALL_DATA} ${WRKSRC}/water320.bmp ${PREFIX}/share/water
	${INSTALL_DATA} ${WRKSRC}/water.txt ${PREFIX}/share/doc/water

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
