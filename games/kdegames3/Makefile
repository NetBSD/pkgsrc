# $NetBSD: Makefile,v 1.65 2012/09/15 10:04:41 obache Exp $

DISTNAME=	kdegames-${_KDE_VERSION}
PKGREVISION=	15
CATEGORIES=	games
COMMENT=	Games for the KDE integrated X11 desktop

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/kde3/Makefile.kde3"

CONFIGURE_ARGS+=	--disable-setgid

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
