# $NetBSD: Makefile,v 1.1.1.1 2001/07/10 09:48:47 zuntum Exp $
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
	${INSTALL_DATA} ${WRKSRC}/water320.bmp ${PREFIX}/share/water

.include "../../devel/SDL/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
