# $NetBSD: Makefile,v 1.70 2013/02/09 22:11:29 ryoon Exp $

DISTNAME=	kdegames-${_KDE_VERSION}
PKGREVISION=	19
CATEGORIES=	games
COMMENT=	Games for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

CONFIGURE_ARGS+=	--disable-setgid

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
