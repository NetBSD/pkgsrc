# $NetBSD: Makefile,v 1.54 2022/08/11 05:08:29 gutteridge Exp $

DISTNAME=	kgoldrunner-${KAPPSVER}
PKGREVISION=	8
CATEGORIES=	games

HOMEPAGE=	https://kde.org/applications/games/kgoldrunner/
COMMENT=	Action game where the hero runs through a maze
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
