# $NetBSD: Makefile,v 1.80 2026/01/07 08:47:03 wiz Exp $

DISTNAME=	killbots-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	games

HOMEPAGE=	https://kde.org/applications/games/killbots/
COMMENT=	KDE port of the classic BSD console game robots
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-kcrash/buildlink3.mk"
.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/kf6-kdbusaddons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
