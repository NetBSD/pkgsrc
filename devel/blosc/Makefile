# $NetBSD: Makefile,v 1.22 2023/09/16 08:07:27 adam Exp $

DISTNAME=	blosc-1.21.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Blosc/}
GITHUB_PROJECT=	c-blosc
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://blosc.org/
COMMENT=	Blocking, shuffling, and lossless compression library
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/blosc
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/blosc
TEST_TARGET=	test

CMAKE_ARGS+=	-DPREFER_EXTERNAL_LZ4=ON
CMAKE_ARGS+=	-DPREFER_EXTERNAL_SNAPPY=ON
CMAKE_ARGS+=	-DPREFER_EXTERNAL_ZLIB=ON
CMAKE_ARGS+=	-DPREFER_EXTERNAL_ZSTD=ON

# error: 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=	c99

# Needed to use posix_memalign, see tests/test_common.h
CFLAGS+=	-D_POSIX_C_SOURCE=200112

CFLAGS.SunOS+=	-D__EXTENSIONS__

PKGCONFIG_OVERRIDE+=	blosc.pc.in

.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
