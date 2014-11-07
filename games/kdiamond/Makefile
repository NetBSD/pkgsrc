# $NetBSD: Makefile,v 1.15 2014/11/07 19:39:31 adam Exp $

DISTNAME=	kdiamond-${_KDE_VERSION}
PKGREVISION=	5
CATEGORIES=	games
COMMENT=	build lines of three similar diamonds

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
