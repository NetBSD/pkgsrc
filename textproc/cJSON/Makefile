# $NetBSD: Makefile,v 1.5 2024/05/13 14:22:16 adam Exp $

DISTNAME=	cJSON-1.7.18
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=DaveGamble/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	tpaul@NetBSD.org
HOMEPAGE=	https://github.com/DaveGamble/cJSON
COMMENT=	Ultralightweight JSON parser in ANSI C
LICENSE=	mit

CMAKE_ARGS+=	-DENABLE_CJSON_UTILS=ON
CMAKE_ARGS+=	-DENABLE_CUSTOM_COMPILER_FLAGS=OFF
CMAKE_ARGS+=	-DBUILD_SHARED_AND_STATIC_LIBS=ON
TEST_TARGET=	test
TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}

PKGCONFIG_OVERRIDE+=	library_config/libcjson_utils.pc.in
PKGCONFIG_OVERRIDE+=	library_config/libcjson.pc.in

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
