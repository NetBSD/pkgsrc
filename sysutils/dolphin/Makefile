# $NetBSD: Makefile,v 1.41 2026/01/27 08:40:33 wiz Exp $

DISTNAME=	dolphin-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	sysutils

HOMEPAGE=	https://apps.kde.org/dolphin/
COMMENT=	KDE File Manager
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools
DEPENDS+=	kio-extras>=${KAPPSVER}:../../devel/kio-extras

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-kbookmarks/buildlink3.mk"
.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../devel/kf6-kcolorscheme/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-kcrash/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-knotifications/buildlink3.mk"
.include "../../devel/kf6-kparts/buildlink3.mk"
.include "../../graphics/kf6-kiconthemes/buildlink3.mk"
.include "../../misc/kf6-kuserfeedback/buildlink3.mk"
.include "../../net/kf6-knewstuff/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/baloo-widgets/buildlink3.mk"
.include "../../sysutils/kf6-baloo/buildlink3.mk"
.include "../../sysutils/kf6-kdbusaddons/buildlink3.mk"
.include "../../sysutils/kf6-kfilemetadata/buildlink3.mk"
.include "../../sysutils/kf6-solid/buildlink3.mk"
.include "../../textproc/kf6-kcodecs/buildlink3.mk"
.include "../../textproc/kf6-kcompletion/buildlink3.mk"
.include "../../x11/kf6-kguiaddons/buildlink3.mk"
.include "../../x11/kf6-ktextwidgets/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/kf6-kwindowsystem/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"


