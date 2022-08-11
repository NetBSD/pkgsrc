# $NetBSD: Makefile,v 1.53 2022/08/11 05:08:31 gutteridge Exp $

DISTNAME=	kspaceduel-${KAPPSVER}
PKGREVISION=	8
CATEGORIES=	games

HOMEPAGE=	https://kde.org/applications/games/kspaceduel/
COMMENT=	Two player game with shooting spaceships flying around a sun
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
