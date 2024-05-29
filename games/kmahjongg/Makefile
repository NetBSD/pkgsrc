# $NetBSD: Makefile,v 1.70 2024/05/29 16:32:38 adam Exp $

DISTNAME=	kmahjongg-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	games

HOMEPAGE=	https://kde.org/applications/games/kmahjongg/
COMMENT=	Tile matching game for one or two players
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../games/libkdegames/buildlink3.mk"
.include "../../games/libkmahjongg/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
