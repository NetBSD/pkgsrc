# $NetBSD: Makefile,v 1.12 2022/05/16 17:09:50 jperkin Exp $

DISTNAME=	oneTBB-2021.3.0
PKGNAME=	${DISTNAME:S/oneTBB-/threadingbuildingblocks-/}
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=oneapi-src/}
GITHUB_PROJECT=	oneTBB
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	https://www.threadingbuildingblocks.org/
COMMENT=	Threading Buildling Blocks
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_LANGUAGES=	c c++11
CMAKE_ARGS+=	-DTBB_STRICT=OFF
TEST_TARGET=	test

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/src/tbb/def/lin64-tbb.def
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/src/tbbmalloc/def/lin64-tbbmalloc.def
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/src/tbbmalloc_proxy/def/lin64-proxy.def

.include "../../mk/atomic64.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
