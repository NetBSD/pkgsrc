# $NetBSD: Makefile,v 1.38 2022/01/10 01:46:43 ryoon Exp $

DISTNAME=	qbittorrent-4.3.9
PKGREVISION=	2
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
USE_LANGUAGES=	c gnu++14
USE_TOOLS+=	pkg-config
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

GCC_REQD+=	6 # c++14

LDFLAGS.NetBSD+=	-ljemalloc

.include "../../devel/boost-libs/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.11
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libtorrent-rasterbar/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.if ${OPSYS} == "Darwin"
.  include "../../x11/qt5-qtmacextras/buildlink3.mk"
.endif
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
