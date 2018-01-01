# $NetBSD: Makefile,v 1.35 2018/01/01 21:18:27 adam Exp $

DISTNAME=	khangman-${_KDE_VERSION}
PKGREVISION=	9
CATEGORIES=	games
COMMENT=	KDE hangman game

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/libkdeedu/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
