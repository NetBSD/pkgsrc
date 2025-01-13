# $NetBSD: Makefile,v 1.41 2025/01/13 10:37:08 adam Exp $

DISTNAME=	mold-2.36.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rui314/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rui314/mold
COMMENT=	High performance drop-in replacement for existing Unix linkers
LICENSE=	mit

# This package uses a lot of C++20 features. GCC 10 is the oldest GCC that can
# build it.
USE_CXX_FEATURES=	c++20
USE_LANGUAGES=		c c++
TEST_TARGET=		test

CMAKE_CONFIGURE_ARGS+=	-DMOLD_USE_SYSTEM_MIMALLOC=ON
CMAKE_CONFIGURE_ARGS+=	-DMOLD_USE_SYSTEM_TBB=ON

# Handle linker flags for dlopen and pthread automatically.
DL_AUTO_VARS=		yes
PTHREAD_AUTO_VARS=	yes

PLIST_VARS+=	wrapper
.include "../../mk/bsd.prefs.mk"
# mold-wrapper is not built on macOS nor Windows
.if ${OPSYS} != "Darwin"
PLIST.wrapper=	yes
.endif

.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/mimalloc/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../parallel/threadingbuildingblocks/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
