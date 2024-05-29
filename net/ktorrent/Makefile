# $NetBSD: Makefile,v 1.130 2024/05/29 16:33:56 adam Exp $

DISTNAME=	ktorrent-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	net

HOMEPAGE=	https://apps.kde.org/ktorrent/
COMMENT=	Graphical BitTorrent client for KDE
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

# disable until plasma-workspace is available
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_LibKWorkspace=TRUE

.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../devel/kparts/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/kplotting/buildlink3.mk"
.include "../../multimedia/phonon-qt5/buildlink3.mk"
.include "../../net/kdnssd/buildlink3.mk"
.include "../../net/libktorrent/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/syndication/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
