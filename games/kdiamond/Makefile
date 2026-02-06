# $NetBSD: Makefile,v 1.83 2026/02/06 10:04:47 wiz Exp $

DISTNAME=	kdiamond-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	games

HOMEPAGE=	https://kde.org/applications/games/kdiamond/
COMMENT=	Build lines of three similar diamonds
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-knotifyconfig/buildlink3.mk"
.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
