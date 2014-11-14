# $NetBSD: Makefile,v 1.16 2014/11/14 08:49:38 markd Exp $

DISTNAME=	kbreakout-${_KDE_VERSION}
CATEGORIES=	games
COMMENT=	a Breakout-like game

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
