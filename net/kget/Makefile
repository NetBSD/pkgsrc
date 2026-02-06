# $NetBSD: Makefile,v 1.92 2026/02/06 10:05:33 wiz Exp $

DISTNAME=	kget-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	net

HOMEPAGE=	https://kde.org/applications/internet/kget/
COMMENT=	Download manager for KDE
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	pkg-config msgmerge

# disable until plasma-workspace is available
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_LibKWorkspace=TRUE

REPLACE_PERL+=	conf/kget_sensitive.pl conf/kget_limitdownloads.pl

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../devel/kf6-knotifyconfig/buildlink3.mk"
.include "../../devel/kf6-kparts/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kf6-kstatusnotifieritem/buildlink3.mk"
.include "../../net/libktorrent/buildlink3.mk"
.include "../../net/libmms/buildlink3.mk"
.include "../../security/qgpgme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
