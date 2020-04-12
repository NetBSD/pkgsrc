# $NetBSD: Makefile,v 1.19 2020/04/12 06:17:06 adam Exp $

DISTNAME=	libjpeg-turbo-2.0.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libjpeg-turbo/}

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	https://libjpeg-turbo.org/
COMMENT=	Accelerated libjpeg with SIMD instructions
LICENSE=	gnu-lgpl-v2 # OR wxWindows Library Licence, Version 3.1

# Note also that libjpeg-turbo's library has a different major version
# number (8) than that installed by the jpeg package (9).
#   https://libjpeg-turbo.org/About/Jpeg-9
CONFLICTS=	jpeg-[0-9]*

.if ${MACHINE_ARCH} == x86_64 || ${MACHINE_ARCH} == i386
BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm
.endif

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE=	release/libturbojpeg.pc.in release/libjpeg.pc.in
TEST_ENV+=		LD_LIBRARY_PATH=${WRKSRC}
TEST_TARGET=		test

# Ask for compatibility with jpeg 8, to get the highest ABI that
# libjpeg-turbo supports.
CMAKE_ARGS+=	-DWITH_JPEG8=ON

CHECK_PORTABILITY_SKIP+=	release/makemacpkg.in

.include "../../mk/bsd.pkg.mk"
