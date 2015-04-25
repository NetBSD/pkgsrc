# $NetBSD: Makefile,v 1.18 2015/04/25 14:22:59 tnn Exp $

DISTNAME=	kolf-${_KDE_VERSION}
PKGREVISION=	2
CATEGORIES=	games
COMMENT=	a miniature golf game for KDE

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
