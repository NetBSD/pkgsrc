# $NetBSD: Makefile,v 1.23 2004/04/20 13:35:28 markd Exp $

DISTNAME=	kdeartwork-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Artwork for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK3=		YES

DEPENDS+=	xscreensaver>=4.14:../../x11/xscreensaver

.include "../../mk/bsd.prefs.mk"

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
