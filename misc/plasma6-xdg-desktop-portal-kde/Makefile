# $NetBSD: Makefile,v 1.3 2026/01/27 08:40:13 wiz Exp $

DISTNAME=	xdg-desktop-portal-kde-${PLASMAVER}
PKGREVISION=	2
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	Backend implementation for xdg-desktop-portal using Qt/KF6
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/plasma6.mk"

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-kcrash/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-knotifications/buildlink3.mk"
.include "../../devel/kf6-kservice/buildlink3.mk"
.include "../../devel/plasma-wayland-protocols/buildlink3.mk"
.include "../../devel/plasma6-kwayland/buildlink3.mk"
.include "../../graphics/kf6-kiconthemes/buildlink3.mk"
.include "../../misc/kf6-kstatusnotifieritem/buildlink3.mk"
.include "../../x11/kf6-kglobalaccel/buildlink3.mk"
.include "../../x11/kf6-kguiaddons/buildlink3.mk"
.include "../../x11/kf6-kirigami/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/kf6-kwindowsystem/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
