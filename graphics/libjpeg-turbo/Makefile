# $NetBSD: Makefile,v 1.48 2026/08/17 15:27:47 ryoon Exp $

DISTNAME=	libjpeg-turbo-3.2.0
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=libjpeg-turbo/}

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	https://libjpeg-turbo.org/
COMMENT=	Accelerated libjpeg with SIMD instructions
LICENSE=	gnu-lgpl-v2 AND ijg # OR wxWindows Library Licence, Version 3.1

# Note also that libjpeg-turbo's library has a different major version
# number (8) than that installed by the jpeg package (9).
#   https://libjpeg-turbo.org/About/Jpeg-9
CONFLICTS=	jpeg-[0-9]*

.if ${MACHINE_ARCH} == x86_64 || ${MACHINE_ARCH} == i386
TOOL_DEPENDS+=	nasm-[0-9]*:../../devel/nasm
.endif

USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE=	release/libturbojpeg.pc.in release/libjpeg.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${JPEG_DEFAULT:U} == "libjpeg-turbo"
SUPERSEDES+=	jpeg-[0-9]*
.endif

BUILD_DEFS+=	JPEG_DEFAULT

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}
TEST_TARGET=	test

# https://github.com/libjpeg-turbo/libjpeg-turbo/issues/898
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POSITION_INDEPENDENT_CODE=ON
# Ask for compatibility with jpeg 8, to get the highest ABI that
# libjpeg-turbo supports.
CMAKE_CONFIGURE_ARGS+=	-DWITH_JPEG8=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_SYSTEM_ZLIB=ON

CHECK_PORTABILITY_SKIP+=	release/makemacpkg.in

.if ${MACHINE_ARCH} == "i386"
CFLAGS+=	-msse2
.endif

.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
