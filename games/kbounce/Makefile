# $NetBSD: Makefile,v 1.53 2022/08/11 05:08:28 gutteridge Exp $

DISTNAME=	kbounce-${KAPPSVER}
PKGREVISION=	8
CATEGORIES=	games

HOMEPAGE=	https://kde.org/applications/games/kbounce/
COMMENT=	Single player arcade game with the elements of puzzle
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
