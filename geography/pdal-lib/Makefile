# $NetBSD: Makefile,v 1.5 2022/01/18 17:42:26 gdt Exp $

DISTNAME=	PDAL-2.2.0-src
PKGNAME=	${DISTNAME:S/PDAL/pdal-lib/:S/-src//}
PKGREVISION=	4
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=PDAL/}
GITHUB_PROJECT=	PDAL
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	https://pdal.io/
COMMENT=	Point Data Abstraction Library
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

TEST_TARGET=	test

PKGCONFIG_OVERRIDE+=	apps/pdal.pc.in
PKGCONFIG_OVERRIDE+=	vendor/gtest/cmake/gtest.pc.in
PKGCONFIG_OVERRIDE+=	vendor/gtest/cmake/gtest_main.pc.in

CMAKE_ARGS+=	-DBUILD_PLUGIN_CPD=OFF
CMAKE_ARGS+=	-DBUILD_PLUGIN_E57=OFF
CMAKE_ARGS+=	-DBUILD_PLUGIN_FBX=OFF
CMAKE_ARGS+=	-DBUILD_PLUGIN_GEOWAVE=OFF
CMAKE_ARGS+=	-DBUILD_PLUGIN_HDF=ON
CMAKE_ARGS+=	-DBUILD_PLUGIN_I3S=OFF
CMAKE_ARGS+=	-DBUILD_PLUGIN_ICEBRIDGE=OFF
CMAKE_ARGS+=	-DBUILD_PLUGIN_MATLAB=OFF
CMAKE_ARGS+=	-DBUILD_PLUGIN_MBIO=OFF
CMAKE_ARGS+=	-DBUILD_PLUGIN_MRSID=OFF
CMAKE_ARGS+=	-DBUILD_PLUGIN_NITF=OFF
CMAKE_ARGS+=	-DBUILD_PLUGIN_OCI=OFF
CMAKE_ARGS+=	-DBUILD_PLUGIN_OPENSCENEGRAPH=OFF
CMAKE_ARGS+=	-DBUILD_PLUGIN_PGPOINTCLOUD=OFF
CMAKE_ARGS+=	-DBUILD_PLUGIN_RDBLIB=OFF
CMAKE_ARGS+=	-DBUILD_PLUGIN_RIVLIB=OFF
CMAKE_ARGS+=	-DBUILD_PLUGIN_TILEDB=OFF

CMAKE_ARGS+=	-DWITH_COMPLETION=OFF
CMAKE_ARGS+=	-DWITH_LASZIP=ON
CMAKE_ARGS+=	-DWITH_LAZPERF=OFF
CMAKE_ARGS+=	-DWITH_LZMA=ON
CMAKE_ARGS+=	-DWITH_ZLIB=ON
CMAKE_ARGS+=	-DWITH_ZSTD=ON

.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../devel/hdf5-c++/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../geography/libgeotiff/buildlink3.mk"
.include "../../geography/laszip/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../graphics/pcl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
