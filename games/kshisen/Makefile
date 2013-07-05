# $NetBSD: Makefile,v 1.7 2013/07/05 13:29:32 ryoon Exp $

DISTNAME=	kshisen-${_KDE_VERSION}
PKGREVISION=	4
CATEGORIES=	games
COMMENT=	a solitaire-like game played using the standard set of Mahjong tiles

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../games/libkmahjongg/buildlink3.mk"
.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
