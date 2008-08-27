# $NetBSD: Makefile,v 1.50 2008/08/27 12:18:13 markd Exp $

DISTNAME=	kdeartwork-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Artwork for the KDE integrated X11 desktop

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/kde3/Makefile.kde3"

DEPENDS+=	xscreensaver>=5.05:../../x11/xscreensaver

.include "../../mk/bsd.prefs.mk"

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
