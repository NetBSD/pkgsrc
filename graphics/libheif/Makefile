# $NetBSD: Makefile,v 1.48 2025/05/04 14:55:21 wiz Exp $

DISTNAME=	libheif-1.19.8
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=strukturag/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/strukturag/libheif
COMMENT=	HEIF and AVIF file format decoder and encoder library
LICENSE=	gnu-lgpl-v3

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++17 filesystem

CMAKE_CONFIGURE_ARGS+=	-DWITH_RAV1E=OFF
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_TIFF=ON

PKGCONFIG_OVERRIDE+=	libheif.pc.in

BUILDLINK_TRANSFORM+=	rm:-Werror

TEST_TARGET=	test
TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CONFIGURE_DIR}/${CMAKE_BUILD_DIR}/libheif
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/${CONFIGURE_DIR}/${CMAKE_BUILD_DIR}/libheif

.include "../../devel/cmake/build.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libaom/buildlink3.mk"
.include "../../multimedia/libde265/buildlink3.mk"
.include "../../multimedia/openh264/buildlink3.mk"
.include "../../multimedia/svt-av1/buildlink3.mk"
.include "../../multimedia/x265/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
