# $NetBSD: Makefile,v 1.28 2005/06/29 13:10:17 markd Exp $

DISTNAME=	kdeartwork-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	misc
COMMENT=	Artwork for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"


DEPENDS+=	xscreensaver>=4.19:../../x11/xscreensaver

.include "../../mk/bsd.prefs.mk"

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
