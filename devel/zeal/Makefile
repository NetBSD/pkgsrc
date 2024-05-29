# $NetBSD: Makefile,v 1.19 2024/05/29 16:32:21 adam Exp $

DISTNAME=	zeal-0.6.1
PKGREVISION=	17
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=zealdocs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	mikeandmore@gmail.com
HOMEPAGE=	https://zealdocs.org/
COMMENT=	Offline documentation browser inspired by Dash
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

TOOL_DEPENDS+=	extra-cmake-modules>=5.10.0:../../devel/extra-cmake-modules

INSTALLATION_DIRS=	bin share/applications share/metainfo
INSTALLATION_DIRS+=	share/icons/hicolor/16x16/apps
INSTALLATION_DIRS+=	share/icons/hicolor/24x24/apps
INSTALLATION_DIRS+=	share/icons/hicolor/32x32/apps
INSTALLATION_DIRS+=	share/icons/hicolor/64x64/apps
INSTALLATION_DIRS+=	share/icons/hicolor/128x128/apps

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
