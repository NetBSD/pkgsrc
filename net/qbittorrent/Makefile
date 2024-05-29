# $NetBSD: Makefile,v 1.67 2024/05/29 16:34:02 adam Exp $

DISTNAME=	qbittorrent-4.6.4
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=qbittorrent/}
GITHUB_PROJECT=	qBittorrent
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.qbittorrent.org/
COMMENT=	BitTorrent client in Qt
LICENSE=	gnu-gpl-v2

# c++14 mode is required; also for libtorrent
# https://github.com/qbittorrent/qBittorrent/issues/11425
USE_LANGUAGES=	c gnu++14
USE_TOOLS+=	pkg-config
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
# error "Boost.Stacktrace requires `_Unwind_Backtrace` function
CMAKE_ARGS+=	-DSTACKTRACE=OFF

GCC_REQD+=	10 # c++14

LDFLAGS.NetBSD+=	-ljemalloc

.include "options.mk"

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.11
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libtorrent-rasterbar/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
