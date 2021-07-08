# $NetBSD: Makefile,v 1.16 2021/07/08 14:59:24 prlw1 Exp $

DISTNAME=	VTK-9.0.3
PKGNAME=	${DISTNAME:S/VTK/vtk/}
CATEGORIES=	graphics
MASTER_SITES=	https://www.vtk.org/files/release/9.0/

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://vtk.org/
COMMENT=	Visualization toolkit
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c c++11

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release


MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/build/lib
#MAKE_ENV+=	CPPFLAGS=-I/usr/pkg/include

post-extract:
	mkdir ${WRKSRC}/build

BUILD_DEPENDS=	ninja-build-[0-9]*:../../devel/ninja-build

CMAKE_ARGS+=	-DVTK_LEGACY_REMOVE=ON
CMAKE_ARGS+=	-DVTK_USE_MPI=OFF
CMAKE_ARGS+=	-DVTK_USE_CUDA=OFF
CMAKE_ARGS+=	-DVTK_ENABLE_LOGGING=OFF
CMAKE_ARGS+=	-DVTK_BUILD_ALL_MODULES=OFF
CMAKE_ARGS+=	-DVTK_ENABLE_REMOTE_MODULES=OFF
CMAKE_ARGS+=	-DVTK_ENABLE_KITS=OFF
CMAKE_ARGS+=	-DVTK_USE_EXTERNAL=ON
CMAKE_ARGS+=	-DVTK_USE_TK=OFF
CMAKE_ARGS+=	-DVTK_ENABLE_WRAPPING=OFF
CMAKE_ARGS+=	-DVTK_WRAP_PYTHON=OFF
CMAKE_ARGS+=	-DVTK_WRAP_JAVA=OFF
CMAKE_ARGS+=	-DVTK_FORBID_DOWNLOADS=ON
# https://discourse.vtk.org/t/9-0-0-rc1-contextopengl2-not-built/2933
CMAKE_ARGS+=	-DVTK_MODULE_ENABLE_VTK_RenderingContextOpenGL2=YES

.include "options.mk"

.include "../../archivers/lz4/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
#.include "../../devel/loguru/buildlink3.mk"
.include "../../devel/netcdf-cxx/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gl2ps/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/double-conversion/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../print/libharu/buildlink3.mk"
.include "../../textproc/PEGTL/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/pugixml/buildlink3.mk"
.include "../../textproc/utf8-cpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
