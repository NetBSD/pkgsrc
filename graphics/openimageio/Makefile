# $NetBSD: Makefile,v 1.96 2023/10/15 19:52:09 ryoon Exp $

DISTNAME=	OpenImageIO-2.5.4.0
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=AcademySoftwareFoundation/}
GITHUB_PROJECT=	OpenImageIO
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://openimageio.readthedocs.io/
COMMENT=	C++ library for reading and writing images
LICENSE=	modified-bsd

UNLIMIT_RESOURCES=	datasize virtualsize

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
TEST_TARGET=		test

CMAKE_ARGS+=		-DSTOP_ON_WARNING=OFF # Disable -Werror
CMAKE_ARGS+=		-DBUILD_MISSING_ROBINMAP=OFF
CMAKE_ARGS+=		-DUSE_EXTERNAL_PUGIXML=ON
CMAKE_ARGS+=		-DUSE_PYTHON:BOOL=OFF
CMAKE_ARGS+=		-DROBINMAP_INCLUDE_DIR=${BUILDLINK_PREFIX.robin-map}/include
CMAKE_ARGS+=		-DOpenJpeg_ROOT=${BUILDLINK_PREFIX.openjpeg}
CMAKE_ARGS+=		-DOpenEXR_ROOT=${BUILDLINK_PREFIX.openexr}

# none of these are available in pkgsrc yet
CMAKE_ARGS+=		-DUSE_DCMTK=OFF
CMAKE_ARGS+=		-DUSE_Libsquish=OFF
CMAKE_ARGS+=		-DUSE_Nuke=OFF
CMAKE_ARGS+=		-DUSE_OpenVDB=OFF
CMAKE_ARGS+=		-DUSE_PTex=OFF
CMAKE_ARGS+=		-DUSE_Field3D=OFF

# only used for the image viewer test application
CMAKE_ARGS+=		-DCMAKE_DISABLE_FIND_PACKAGE_Qt5=ON

# disabled by default in arch linux, freebsd...
CMAKE_ARGS+=		-DUSE_HDF5=OFF
CMAKE_ARGS+=		-DUSE_FFmpeg=OFF
CMAKE_ARGS+=		-DUSE_OpenCV=OFF

# We're using cmake...
CHECK_PORTABILITY_SKIP+=	Makefile

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/robin-map/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/libheif/buildlink3.mk"
.include "../../graphics/libraw/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/opencolorio/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../parallel/threadingbuildingblocks/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../textproc/pugixml/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
