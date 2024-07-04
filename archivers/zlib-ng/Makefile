# $NetBSD: Makefile,v 1.5 2024/07/04 10:56:37 adam Exp $

DISTNAME=	zlib-ng-2.2.1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=zlib-ng/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zlib-ng/zlib-ng
COMMENT=	Replacement for zlib with optimizations for "next generation" systems
LICENSE=	zlib

USE_CC_FEATURES=	c11
USE_LANGUAGES=		c c++
CMAKE_CONFIGURE_ARGS+=	-DWITH_GTEST=OFF

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,${WRKSRC}/zlib-ng.map

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}
TEST_TARGET=	test

PKGCONFIG_OVERRIDE+=	zlib.pc.cmakein

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
