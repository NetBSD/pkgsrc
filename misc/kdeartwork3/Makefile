# $NetBSD: Makefile,v 1.36 2006/05/16 14:57:06 tron Exp $

DISTNAME=	kdeartwork-${_KDE_VERSION}
PKGREVISION=	2
CATEGORIES=	misc
COMMENT=	Artwork for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"


DEPENDS+=	xscreensaver>=4.22nb4:../../x11/xscreensaver

.include "../../mk/bsd.prefs.mk"

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
