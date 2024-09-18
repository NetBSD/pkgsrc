# $NetBSD: Makefile,v 1.6 2024/09/18 10:46:42 adam Exp $

DISTNAME=	zlib-ng-2.2.2
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
