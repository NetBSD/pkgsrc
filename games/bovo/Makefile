# $NetBSD: Makefile,v 1.39 2020/06/09 11:56:06 markd Exp $

DISTNAME=	bovo-${KAPPSVER}
CATEGORIES=	games

HOMEPAGE=	https://kde.org/applications/games/bovo/
COMMENT=	Five-in-a-row Board Game
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
