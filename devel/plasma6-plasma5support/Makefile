# $NetBSD: Makefile,v 1.3 2026/01/27 08:39:17 wiz Exp $

DISTNAME=	plasma5support-${PLASMAVER}
PKGREVISION=	2
CATEGORIES=	devel

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	Support components for porting from KF5/Qt5 to KF6/Qt6
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/plasma6.mk"

USE_TOOLS+=	msgmerge

.include "../../mk/bsd.prefs.mk"

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kidletime/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-knotifications/buildlink3.mk"
.include "../../devel/kf6-kservice/buildlink3.mk"
.include "../../misc/kf6-kunitconversion/buildlink3.mk"
.include "../../time/kf6-kholidays/buildlink3.mk"
.include "../../sysutils/kf6-solid/buildlink3.mk"
.include "../../sysutils/plasma6-libksysguard/buildlink3.mk"
.include "../../x11/kf6-kguiaddons/buildlink3.mk"
.include "../../x11/plasma6-plasma-activities/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
