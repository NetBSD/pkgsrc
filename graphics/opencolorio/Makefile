# $NetBSD: Makefile,v 1.9 2023/10/15 19:45:33 ryoon Exp $

DISTNAME=	OpenColorIO-2.2.1
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=AcademySoftwareFoundation/}
GITHUB_PROJECT=	OpenColorIO
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://opencolorio.org/
COMMENT=	Color management solution
LICENSE=	modified-bsd AND mit

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	gnu99 gnu++14 # alloca(3)
BUILDLINK_TRANSFORM+=	opt:-std=c++14:-std=gnu++14 # alloca(3)

USE_CXX_FEATURES+=	c++11

CMAKE_CONFIGURE_ARGS+=	-DUSE_EXTERNAL_TINYXML:BOOL=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_EXTERNAL_YAML:BOOL=ON
CMAKE_CONFIGURE_ARGS+=	-DOCIO_BUILD_APPS:BOOL=OFF
CMAKE_CONFIGURE_ARGS+=	-DOCIO_BUILD_SHARED:BOOL=ON
CMAKE_CONFIGURE_ARGS+=	-DOCIO_BUILD_PYGLUE:BOOL=OFF

.if ${MACHINE_ARCH} != "i386" && ${MACHINE_ARCH} != "x86_64"
CMAKE_CONFIGURE_ARGS+=	-DOCIO_USE_SSE:BOOL=OFF
.endif

PKGCONFIG_OVERRIDE+=	src/OpenColorIO/res/OpenColorIO.pc.in

BUILDLINK_TRANSFORM+=	rm:-Werror

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}

pre-configure:
	${MKDIR} ${WRKSRC}/${OBJDIR}

.include "../../archivers/minizip-ng/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../devel/pystring/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../math/imath/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/yaml-cpp/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../devel/cmake/build.mk"
PY_PATCHPLIST=	yes
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
