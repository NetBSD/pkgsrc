# $NetBSD: Makefile,v 1.94 2026/05/12 06:52:27 wiz Exp $

DISTNAME=	kstars-3.8.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_KDE:=kstars/${PKGVERSION_NOREV}/}

HOMEPAGE=	https://kstars.kde.org/
COMMENT=	KDE desktop planetarium
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge pkg-config

CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_WITH_QT6=ON

.include "../../devel/cfitsio/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcrash/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-knotifications/buildlink3.mk"
.include "../../devel/kf6-knotifyconfig/buildlink3.mk"
.include "../../geography/libnova/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/kf6-kplotting/buildlink3.mk"
.include "../../graphics/libraw/buildlink3.mk"
.include "../../graphics/opencv/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../graphics/wcslib/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../misc/indi/buildlink3.mk"
.include "../../misc/stellarsolver/buildlink3.mk"
.include "../../net/kf6-knewstuff/buildlink3.mk"
.include "../../net/qt6-qtwebsockets/buildlink3.mk"
.include "../../security/qt6-qtkeychain/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
