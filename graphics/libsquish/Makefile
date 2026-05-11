# $NetBSD: Makefile,v 1.2 2026/05/11 13:11:43 adam Exp $

DISTNAME=	libsquish-1.15.1.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=oblivioncth/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

GITHUB_SUBMODULES=	oblivioncth OBCMake v0.3.12 ${CMAKE_BUILD_DIR}/_deps/obcmake-src

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://oblivioncth.github.io/libsquish
COMMENT=	Open source DXT compression library
LICENSE=	mit

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DNO_VERBOSE_VERSION=ON # requires git

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
