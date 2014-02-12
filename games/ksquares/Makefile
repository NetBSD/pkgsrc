# $NetBSD: Makefile,v 1.11 2014/02/12 23:17:57 tron Exp $

DISTNAME=	ksquares-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	games
COMMENT=	game of Dots and Boxes

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
