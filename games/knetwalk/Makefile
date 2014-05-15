# $NetBSD: Makefile,v 1.13 2014/05/15 14:41:49 adam Exp $

DISTNAME=	knetwalk-${_KDE_VERSION}
PKGREVISION=	3
CATEGORIES=	games
COMMENT=	a game for system administrators

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
