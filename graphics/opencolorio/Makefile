# $NetBSD: Makefile,v 1.6 2019/09/22 23:40:29 nia Exp $

DISTNAME=	OpenColorIO-1.1.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=imageworks/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/imageworks/OpenColorIO/
COMMENT=	Color management solution
LICENSE=	modified-bsd AND mit

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++11

# C++11
GCC_REQD+=	4.8

CMAKE_ARGS+=	-DUSE_EXTERNAL_TINYXML:BOOL=ON
CMAKE_ARGS+=	-DUSE_EXTERNAL_YAML:BOOL=ON
CMAKE_ARGS+=	-DOCIO_BUILD_APPS:BOOL=OFF
CMAKE_ARGS+=	-DOCIO_BUILD_SHARED:BOOL=ON
CMAKE_ARGS+=	-DOCIO_BUILD_PYGLUE:BOOL=OFF

PKGCONFIG_OVERRIDE+=	export/pkgconfig/OpenColorIO.pc.in

BUILDLINK_TRANSFORM+=	rm:-Werror

INSTALLATION_DIRS+=	lib/cmake/OpenColorIO

post-install:
	${MV} ${DESTDIR}${PREFIX}/lib/static/*.a ${DESTDIR}${PREFIX}/lib
	${MV} ${DESTDIR}${PREFIX}/*.cmake ${DESTDIR}${PREFIX}/lib/cmake/OpenColorIO
	${MV} ${DESTDIR}${PREFIX}/cmake/*.cmake ${DESTDIR}${PREFIX}/lib/cmake/OpenColorIO

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../textproc/yaml-cpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
