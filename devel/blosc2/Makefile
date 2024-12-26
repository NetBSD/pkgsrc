# $NetBSD: Makefile,v 1.23 2024/12/26 08:01:51 adam Exp $

DISTNAME=	blosc2-2.15.2
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

CMAKE_CONFIGURE_ARGS+=	-DBUILD_EXAMPLES=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_FUZZERS=OFF
CMAKE_CONFIGURE_ARGS+=	-DPREFER_EXTERNAL_LZ4=ON
CMAKE_CONFIGURE_ARGS+=	-DPREFER_EXTERNAL_ZLIB=ON
CMAKE_CONFIGURE_ARGS+=	-DPREFER_EXTERNAL_ZSTD=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_C_FLAGS=${CFLAGS:Q}

# Needed to use posix_memalign, see tests/test_common.h
# TODO: as-is, breaks NetBSD
#CFLAGS+=	-D_POSIX_C_SOURCE=200112

CFLAGS.SunOS+=	-D__EXTENSIONS__

PKGCONFIG_OVERRIDE+=	blosc.pc.in

.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/zlib-ng/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
