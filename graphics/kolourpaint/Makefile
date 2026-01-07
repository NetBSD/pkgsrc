# $NetBSD: Makefile,v 1.93 2026/01/07 08:47:21 wiz Exp $

DISTNAME=	kolourpaint-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	graphics

HOMEPAGE=	https://kde.org/applications/graphics/kolourpaint/
COMMENT=	KDE paint program
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libksane/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
