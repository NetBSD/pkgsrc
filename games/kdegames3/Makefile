# $NetBSD: Makefile,v 1.49 2008/02/20 10:20:56 markd Exp $

DISTNAME=	kdegames-${_KDE_VERSION}
CATEGORIES=	games
COMMENT=	Games for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

CONFIGURE_ARGS+=	--disable-setgid

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
