# $NetBSD: Makefile,v 1.31 2019/11/18 10:13:28 markd Exp $

DISTNAME=	knavalbattle-${KAPPSVER}
CATEGORIES=	games

HOMEPAGE=	https://kde.org/applications/games/knavalbattle/
COMMENT=	Network-enabled implementation of the famous ship sinking game for KDE
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=${KF5VER}:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
