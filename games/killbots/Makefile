# $NetBSD: Makefile,v 1.29 2019/07/01 04:08:13 ryoon Exp $

DISTNAME=	killbots-${_KDE_VERSION}
PKGREVISION=	13
CATEGORIES=	games
COMMENT=	KDE port of the classic BSD console game robots

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
