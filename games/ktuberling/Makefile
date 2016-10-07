# $NetBSD: Makefile,v 1.20 2016/10/07 18:25:49 adam Exp $

DISTNAME=	ktuberling-${_KDE_VERSION}
PKGREVISION=	4
CATEGORIES=	games
COMMENT=	kids game: make your own potato

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
