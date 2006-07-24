# $NetBSD: Makefile,v 1.39 2006/07/24 12:24:11 joerg Exp $

DISTNAME=	kdeartwork-${_KDE_VERSION}
PKGREVISION=	2
CATEGORIES=	misc
COMMENT=	Artwork for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"


DEPENDS+=	xscreensaver>=5.00:../../x11/xscreensaver

.include "../../mk/bsd.prefs.mk"

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
