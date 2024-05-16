# $NetBSD: Makefile,v 1.43 2024/05/16 06:15:04 wiz Exp $

DISTNAME=	VTK-9.2.6
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	https://www.vtk.org/files/release/${PKGVERSION_NOREV:R}/

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	https://vtk.org/
COMMENT=	Visualization toolkit
LICENSE=	modified-bsd

TOOL_DEPENDS=	ninja-build-[0-9]*:../../devel/ninja-build

USE_CMAKE=	yes
USE_LANGUAGES=	c c++11

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
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
# A header-only C++ lib shipped with VTK. Non-versioned archive with the
# 1.5M header at http://www.partow.net/downloads/exprtk.zip .
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_exprtk=OFF
# The fork needed by forked ioss.
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_fmt=OFF
# SEACAS ioss. Uneasy about packaging that. No proper releases, even.
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_ioss=OFF
# Verdict, some quadrature computations in 2D, 3D. Unsure if useful as pkg.
CMAKE_ARGS+=	-DVTK_MODULE_USE_EXTERNAL_VTK_verdict=OFF

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/build/lib

PLIST_VARS+=	cocoa opengl
PLIST_SUBST+=	VTKVER=${PKGVERSION_NOREV:C/([0-9]+\.[0-9]+).*/\1/}

CHECK_PORTABILITY_SKIP+=	Examples/Build/vtkMy/Utilities/Doxygen/doc_makeall.sh.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
PLIST.cocoa=	yes
.else
PLIST.opengl=	yes
.endif

post-extract:
	${MKDIR} ${WRKSRC}/build

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
# not compatible, misses specializations in vendored vork
#.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"
.include "../../science/cgnslib/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
