# $NetBSD: Makefile,v 1.21 2004/02/04 20:51:46 markd Exp $

DISTNAME=	kdeartwork-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Artwork for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

DEPENDS+=	xscreensaver>=4.14:../../x11/xscreensaver

.include "../../mk/bsd.prefs.mk"

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
