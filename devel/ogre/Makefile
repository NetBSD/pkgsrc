# $NetBSD: Makefile,v 1.54 2023/11/12 13:21:08 wiz Exp $

DISTNAME=	ogre-1.12.11
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=OGRECave/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OGRECave/ogre
COMMENT=	Scene-oriented, flexible 3D engine written in C++
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_LANGUAGES+=	gnu++11	# uses alloca()

USE_CXX_FEATURES+=	c++11 put_time

# Unsupported on some pkgsrc platforms (e.g. NetBSD).
# It attempts to enable them solely based on the compiler version, which
# doesn't work, and does not include good fallback.
CMAKE_ARGS+=	-DOGRE_ENABLE_PRECOMPILED_HEADERS=OFF

CMAKE_ARGS+=	-DOGRE_BUILD_DEPENDENCIES=OFF
CMAKE_ARGS+=	-DOGRE_BUILD_COMPONENT_PYTHON=OFF
CMAKE_ARGS+=	-DOGRE_BUILD_COMPONENT_JAVA=OFF

# Mostly going by which dependencies other distributors enable by default to
# determine what is useful to include.
# Qt5 and SDL2 are only used by example programs.
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_ASSIMP=ON
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Cg=ON
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Doxygen=ON
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_OpenEXR=ON
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_PythonInterp=ON
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_PythonLibs=ON
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Qt5=ON
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_SDL2=ON
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Softimage=ON
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_SWIG=ON

PKGCONFIG_OVERRIDE+=	CMake/Templates/*.pc.in

PLIST_VARS+=	glesv2
.include "../../graphics/MesaLib/features.mk"
.if ${MESALIB_SUPPORTS_GLESv2:tl} != "no"
PLIST.glesv2=	yes
.endif

.include "../../archivers/zziplib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeimage/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../textproc/pugixml/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
