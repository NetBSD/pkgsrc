# $NetBSD: Makefile,v 1.22 2024/11/13 12:43:14 wiz Exp $

DISTNAME=	zeal-0.7.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=zealdocs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	mikeandmore@gmail.com
HOMEPAGE=	https://zealdocs.org/
COMMENT=	Offline documentation browser inspired by Dash
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	extra-cmake-modules>=5.10.0:../../devel/extra-cmake-modules

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin share/applications share/metainfo
INSTALLATION_DIRS+=	share/icons/hicolor/16x16/apps
INSTALLATION_DIRS+=	share/icons/hicolor/24x24/apps
INSTALLATION_DIRS+=	share/icons/hicolor/32x32/apps
INSTALLATION_DIRS+=	share/icons/hicolor/64x64/apps
INSTALLATION_DIRS+=	share/icons/hicolor/128x128/apps

.include "../../devel/cmake/build.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../x11/qt5-qtwebchannel/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
