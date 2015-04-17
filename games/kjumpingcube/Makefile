# $NetBSD: Makefile,v 1.17 2015/04/17 15:53:04 adam Exp $

DISTNAME=	kjumpingcube-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	games
COMMENT=	a simple tactical game for KDE

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
