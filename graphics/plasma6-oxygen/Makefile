# $NetBSD: Makefile,v 1.4 2026/01/27 08:39:47 wiz Exp $

DISTNAME=	oxygen-${PLASMAVER}
PKGREVISION=	2
CATEGORIES=	graphics

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	KDE Oxygen style
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/plasma6.mk"

USE_TOOLS+=	msgmerge pkg-config

CMAKE_CONFIGURE_ARGS+=	-DBUILD_QT5=OFF

.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../devel/plasma6-kwayland/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kf6-frameworkintegration/buildlink3.mk"
.include "../../x11/plasma6-kdecoration/buildlink3.mk"
.include "../../x11/plasma6-libplasma/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
