# $NetBSD: Makefile,v 1.5 2026/11/08 14:02:39 ryoon Exp $

DISTNAME=	ptex-2.5.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=wdas/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ptex.us/
COMMENT=	Per-Face Texture Mapping for Production Rendering
LICENSE=	modified-bsd # with slightly changes spelling

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DPTEX_SHA=${PKGVERSION_NOREV}
CMAKE_CONFIGURE_ARGS+=	-DPTEX_VER=${PKGVERSION_NOREV}

TEST_TARGET=	test

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/src/ptex/

.include "../../devel/cmake/build.mk"

.include "../../devel/libdeflate/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
