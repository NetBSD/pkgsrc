# $NetBSD: Makefile,v 1.112 2024/10/04 03:49:26 ryoon Exp $

DISTNAME=	OpenImageIO-2.5.13.1
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=AcademySoftwareFoundation/}
GITHUB_PROJECT=	OpenImageIO
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://openimageio.readthedocs.io/
COMMENT=	C++ library for reading and writing images
LICENSE=	modified-bsd

UNLIMIT_RESOURCES=	datasize virtualsize

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
TEST_TARGET=	test

CMAKE_CONFIGURE_ARGS+=	-DSTOP_ON_WARNING=OFF # Disable -Werror
CMAKE_CONFIGURE_ARGS+=	-DBUILD_MISSING_ROBINMAP=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_EXTERNAL_PUGIXML=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_PYTHON=OFF
CMAKE_CONFIGURE_ARGS+=	-DROBINMAP_INCLUDE_DIR=${BUILDLINK_PREFIX.robin-map}/include
CMAKE_CONFIGURE_ARGS+=	-DOpenJpeg_ROOT=${BUILDLINK_PREFIX.openjpeg}
CMAKE_CONFIGURE_ARGS+=	-DOpenEXR_ROOT=${BUILDLINK_PREFIX.openexr}

# none of these are available in pkgsrc yet
CMAKE_CONFIGURE_ARGS+=	-DUSE_DCMTK=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_Libsquish=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_Nuke=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_OpenVDB=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_Field3D=OFF

# disable imageviewer since it requires Qt5 to build
CMAKE_CONFIGURE_ARGS+=	-DENABLE_IV=OFF

# disabled by default in arch linux, freebsd...
CMAKE_CONFIGURE_ARGS+=	-DUSE_HDF5=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_FFmpeg=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_OpenCV=OFF

# We're using cmake...
CHECK_PORTABILITY_SKIP+=	Makefile

PKGCONFIG_OVERRIDE=	src/build-scripts/OpenImageIO.pc.in

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
.include "../../graphics/ptex/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../parallel/threadingbuildingblocks/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../textproc/pugixml/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
