# $NetBSD: Makefile,v 1.6.2.1 2020/06/17 13:38:14 bsiegert Exp $

DISTNAME=	qbittorrent-4.2.1
PKGREVISION=	4
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
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
