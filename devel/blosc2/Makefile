# $NetBSD: Makefile,v 1.14 2024/04/02 20:20:12 adam Exp $

DISTNAME=	blosc2-2.14.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Blosc/}
GITHUB_PROJECT=	c-blosc2
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://blosc.org/
COMMENT=	Fast, compressed and persistent data store library for C
LICENSE=	modified-bsd

USE_CC_FEATURES=	c99

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/blosc
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/blosc
TEST_TARGET=	test

CMAKE_ARGS+=	-DBUILD_EXAMPLES=OFF
CMAKE_ARGS+=	-DBUILD_FUZZERS=OFF
CMAKE_ARGS+=	-DPREFER_EXTERNAL_LZ4=ON
CMAKE_ARGS+=	-DPREFER_EXTERNAL_ZLIB=ON
CMAKE_ARGS+=	-DPREFER_EXTERNAL_ZSTD=ON

# Needed to use posix_memalign, see tests/test_common.h
CFLAGS+=	-D_POSIX_C_SOURCE=200112

CFLAGS.SunOS+=	-D__EXTENSIONS__

PKGCONFIG_OVERRIDE+=	blosc.pc.in

.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/zlib-ng/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
