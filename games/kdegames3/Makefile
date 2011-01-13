# $NetBSD: Makefile,v 1.57 2011/01/13 13:36:18 wiz Exp $

DISTNAME=	kdegames-${_KDE_VERSION}
PKGREVISION=	7
CATEGORIES=	games
COMMENT=	Games for the KDE integrated X11 desktop

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/kde3/Makefile.kde3"

CONFIGURE_ARGS+=	--disable-setgid

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
