# $NetBSD: Makefile,v 1.13 2023/01/24 18:36:34 wiz Exp $

DISTNAME=	fmt-9.1.0
PKGNAME=	${DISTNAME:S/fmt/fmtlib/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=fmtlib/}
GITHUB_PROJECT=	fmt

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fmt.dev/
COMMENT=	Formatting library
LICENSE=	mit

USE_LANGUAGES=		c c++11
PKGCONFIG_OVERRIDE=	support/cmake/fmt.pc.in
TEST_ENV+=		LD_LIBRARY_PATH=${WRKSRC}
# For Darwin
TEST_ENV+=		DYLD_LIBRARY_PATH=${WRKSRC}
TEST_TARGET=		test

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
