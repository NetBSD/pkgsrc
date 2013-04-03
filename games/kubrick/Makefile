# $NetBSD: Makefile,v 1.1 2013/04/03 12:03:43 markd Exp $

DISTNAME=	kubrick-${_KDE_VERSION}
CATEGORIES=	games
COMMENT=	a game based on the Rubik's Cube puzzle

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
