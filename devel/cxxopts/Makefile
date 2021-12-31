# $NetBSD: Makefile,v 1.1 2021/12/31 17:23:19 plunky Exp $
#

DISTNAME=	cxxopts-3.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jarro2783/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jarro2783/cxxopts
COMMENT=	Lightweight C++ option parser library
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DCXXOPTS_BUILD_EXAMPLES=OFF
CMAKE_ARGS+=	-DCXXOPTS_BUILD_TESTS=OFF

.include "../../mk/bsd.pkg.mk"
