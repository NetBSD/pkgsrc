# $NetBSD: Makefile,v 1.12 2024/10/02 06:48:01 nia Exp $

DISTNAME=	OpenColorIO-2.3.2
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=AcademySoftwareFoundation/}
GITHUB_PROJECT=	OpenColorIO
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://opencolorio.org/
COMMENT=	Color management solution
LICENSE=	modified-bsd AND mit

USE_CC_FEATURES+=	c99
USE_CXX_FEATURES+=	c++14
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/src/OpenColorIO
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/src/OpenColorIO
TEST_TARGET=	test

CMAKE_CONFIGURE_ARGS+=	-DOCIO_BUILD_APPS:BOOL=OFF
CMAKE_CONFIGURE_ARGS+=	-DOCIO_BUILD_PYGLUE:BOOL=OFF
# Only use pkgsrc dependencies
CMAKE_CONFIGURE_ARGS+=	-DOCIO_INSTALL_EXT_PACKAGES:STRING=NONE

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} != "x86_64"
CMAKE_CONFIGURE_ARGS+=	-DOCIO_BUILD_ENABLE_OPTIMIZATIONS_SSE:BOOL=OFF
.endif

PKGCONFIG_OVERRIDE+=	src/OpenColorIO/res/OpenColorIO.pc.in

BUILDLINK_TRANSFORM+=	rm:-Werror

# Use native macOS OpenGL.
.if ${OPSYS} == "Darwin"
# Tries to download sse2neon.h.
CMAKE_CONFIGURE_ARGS+=	-DOCIO_USE_SSE2NEON=OFF
.else
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.endif

.include "../../devel/cmake/build.mk"

.include "../../archivers/minizip-ng/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../devel/pystring/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.13
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../math/imath/buildlink3.mk"
BUILDLINK_API_DEPENDS.expat+=	expat>=2.4.1
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/yaml-cpp/buildlink3.mk"
PY_PATCHPLIST=	yes
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
