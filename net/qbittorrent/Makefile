# $NetBSD: Makefile,v 1.18 2020/11/21 22:17:56 adam Exp $

DISTNAME=	qbittorrent-4.3.0.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=qbittorrent/}
GITHUB_PROJECT=	qBittorrent
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.qbittorrent.org/
COMMENT=	BitTorrent client in Qt
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
# c++14 mode is required; also for libtorrent
# https://github.com/qbittorrent/qBittorrent/issues/11425
USE_LANGUAGES=	c c++14
USE_TOOLS+=	pkg-config
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"

GCC_REQD+=	6 # c++14

.include "../../mk/bsd.prefs.mk"

# 64 bit atomic ops are required
.if ${MACHINE_ARCH} == "i386"
CXXFLAGS+=		-march=i586
.endif

LDFLAGS.NetBSD+=	-ljemalloc

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libtorrent-rasterbar/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.if ${OPSYS} == "Darwin"
.  include "../../x11/qt5-qtmacextras/buildlink3.mk"
.endif
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
