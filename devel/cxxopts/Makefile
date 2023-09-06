# $NetBSD: Makefile,v 1.2 2023/09/06 17:57:00 bsiegert Exp $
#

DISTNAME=	cxxopts-3.1.1
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
