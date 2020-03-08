# $NetBSD: Makefile,v 1.5 2020/03/08 16:50:58 wiz Exp $

DISTNAME=	qbittorrent-4.2.1
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=qbittorrent/}
GITHUB_PROJECT=	qBittorrent
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.qbittorrent.org/
COMMENT=	BitTorrent client in Qt
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

# C++11
GCC_REQD+=	4.7

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"

LDFLAGS.NetBSD+=	-ljemalloc

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libtorrent-rasterbar/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
