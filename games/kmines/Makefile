# $NetBSD: Makefile,v 1.8 2013/11/07 11:35:50 markd Exp $

DISTNAME=	kmines-${_KDE_VERSION}
CATEGORIES=	games
COMMENT=	KDE version of the classic minesweeper game

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
