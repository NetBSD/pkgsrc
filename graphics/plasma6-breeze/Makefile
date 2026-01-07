# $NetBSD: Makefile,v 1.2 2026/01/07 08:47:25 wiz Exp $

DISTNAME=	breeze-${PLASMAVER}
PKGREVISION=	1
CATEGORIES=	graphics

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	Artwork, styles and assets for Breeze visual style for Plasma Desktop
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v3

.include "../../meta-pkgs/kde/plasma6.mk"

DEPENDS+=	breeze-icons>=6.18.0:../../graphics/breeze-icons

USE_TOOLS+=	msgmerge pkg-config

CMAKE_CONFIGURE_ARGS+=	-DBUILD_QT5=OFF

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/plasma6-kwayland/buildlink3.mk"
.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../x11/kf6-frameworkintegration/buildlink3.mk"
.include "../../x11/kf6-kirigami/buildlink3.mk"
.include "../../x11/plasma6-kdecoration/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
