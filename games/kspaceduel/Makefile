# $NetBSD: Makefile,v 1.9 2014/01/01 11:52:18 wiz Exp $

DISTNAME=	kspaceduel-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	games
COMMENT=	two player game with shooting spaceships flying around a sun.

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
