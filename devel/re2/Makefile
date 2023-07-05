# $NetBSD: Makefile,v 1.12 2023/07/05 22:27:49 wiz Exp $

DISTNAME=	re2-${GITHUB_TAG:S/-//g}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	2023-07-01

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/re2
COMMENT=	Regular expression library
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++11
TEST_ENV=	LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}
TEST_TARGET=	test

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

PKGCONFIG_OVERRIDE=	re2.pc.in
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../devel/abseil/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
