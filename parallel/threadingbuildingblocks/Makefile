# $NetBSD: Makefile,v 1.21 2026/01/07 08:48:32 wiz Exp $

DISTNAME=	oneTBB-2022.0.0
PKGNAME=	${DISTNAME:S/oneTBB-/threadingbuildingblocks-/}
PKGREVISION=	3
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_GITHUB:=oneapi-src/}
GITHUB_PROJECT=	oneTBB
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	https://uxlfoundation.github.io/oneTBB/
COMMENT=	Threading Buildling Blocks
LICENSE=	apache-2.0

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++11

# Use one build directory across platforms.
CMAKE_CONFIGURE_ARGS+=	-DTBB_OUTPUT_DIR_BASE=pkgsrc
CMAKE_CONFIGURE_ARGS+=	-DTBB_STRICT=OFF

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/src/tbb/def/lin64-tbb.def
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/src/tbbmalloc/def/lin64-tbbmalloc.def
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/src/tbbmalloc_proxy/def/lin64-proxy.def

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	lp32 lp64
.if !empty(LP32PLATFORMS:@.PLAT.@${MACHINE_PLATFORM:M${.PLAT.}}@)
PLIST.lp32=	yes
.else
PLIST.lp64=	yes
.endif

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../parallel/hwloc/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
