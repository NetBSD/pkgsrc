# $NetBSD: Makefile,v 1.1 2026/11/08 15:01:00 ryoon Exp $

DISTNAME=	partio-1.20.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=wdas/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/wdas/partio/
COMMENT=	Library for common animation particle formats
LICENSE=	modified-bsd

USE_LANGUAGES=	c++

CMAKE_CONFIGURE_ARGS+=	-DPARTIO_BUILD_PYTHON=OFF
CMAKE_CONFIGURE_ARGS+=	-DPARTIO_BUILD_DOCS=OFF
CMAKE_CONFIGURE_ARGS+=	-DPARTIO_BUILD_TOOLS=OFF
CMAKE_CONFIGURE_ARGS+=	-DPARTIO_ENABLE_TESTING=OFF

.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
