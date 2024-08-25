# $NetBSD: Makefile,v 1.14 2024/08/25 06:19:09 wiz Exp $

DISTNAME=	oneTBB-2021.5.0
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
# Use one build directory across platforms.
CMAKE_CONFIGURE_ARGS+=	-DTBB_OUTPUT_DIR_BASE=pkgsrc
CMAKE_CONFIGURE_ARGS+=	-DTBB_STRICT=OFF
TEST_TARGET=	test
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/pkgsrc_relwithdebinfo

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/src/tbb/def/lin64-tbb.def
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/src/tbbmalloc/def/lin64-tbbmalloc.def
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/src/tbbmalloc_proxy/def/lin64-proxy.def

.include "../../mk/atomic64.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
