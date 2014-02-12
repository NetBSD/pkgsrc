# $NetBSD: Makefile,v 1.21 2014/02/12 23:17:55 tron Exp $

DISTNAME=	khangman-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	games
COMMENT=	KDE hangman game

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/libkdeedu/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
