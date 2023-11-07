# $NetBSD: Makefile,v 1.10 2023/11/07 20:29:25 nros Exp $

DISTNAME=	OpenColorIO-2.2.1
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=AcademySoftwareFoundation/}
GITHUB_PROJECT=	OpenColorIO
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://opencolorio.org/
COMMENT=	Color management solution
LICENSE=	modified-bsd AND mit

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

USE_CC_FEATURES+=	c99
USE_CXX_FEATURES+=	c++14

CMAKE_CONFIGURE_ARGS+=	-DOCIO_BUILD_APPS:BOOL=OFF
CMAKE_CONFIGURE_ARGS+=	-DOCIO_BUILD_PYGLUE:BOOL=OFF
# Only use pkgsrc dependencies
CMAKE_CONFIGURE_ARGS+=	-DOCIO_INSTALL_EXT_PACKAGES:STRING=NONE

.if ${MACHINE_ARCH} != "i386" && ${MACHINE_ARCH} != "x86_64"
CMAKE_CONFIGURE_ARGS+=	-DOCIO_USE_SSE:BOOL=OFF
.endif

PKGCONFIG_OVERRIDE+=	src/OpenColorIO/res/OpenColorIO.pc.in

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/cmake/build.mk"

.include "../../archivers/minizip-ng/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../devel/pystring/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.13
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../math/imath/buildlink3.mk"
BUILDLINK_API_DEPENDS.expat+=	expat>=2.4.1
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/yaml-cpp/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
PY_PATCHPLIST=	yes
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
