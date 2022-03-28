# $NetBSD: Makefile,v 1.4 2022/03/28 10:44:24 tnn Exp $

DISTNAME=	f9036699b53a
PKGNAME=	mojoshader-0.0.20210110
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	https://hg.icculus.org/icculus/mojoshader/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.icculus.org/mojoshader/
COMMENT=	Library to move calls to Direct3D shaders to OpenGL
LICENSE=	zlib

USE_LANGUAGES+=	c c++

WRKSRC=		${WRKDIR}/mojoshader-f9036699b53a
USE_CMAKE=	yes


# FLIP_VIEWPORT is needed by some FNA games (FEZ if I recall correctly)
CMAKE_ARGS=	-DBUILD_SHARED_LIBS=ON \
		-DFLIP_VIEWPORT=1 \
		-DPROFILE_METAL=OFF

INSTALLATION_DIRS=	lib include

# No upstream install target
do-install:
	${INSTALL_DATA} ${WRKSRC}/mojoshader*.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libmojoshader.so ${DESTDIR}${PREFIX}/lib

.include "../../graphics/vulkan-headers/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
