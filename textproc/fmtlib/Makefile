# $NetBSD: Makefile,v 1.20 2024/08/25 06:19:15 wiz Exp $

DISTNAME=	fmt-11.0.2
PKGNAME=	${DISTNAME:S/fmt/fmtlib/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=fmtlib/}
GITHUB_PROJECT=	fmt

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fmt.dev/
COMMENT=	Formatting library
LICENSE=	mit

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
PKGCONFIG_OVERRIDE=	support/cmake/fmt.pc.in
TEST_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}
# For Darwin
TEST_ENV+=		DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}
TEST_TARGET=		test

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
