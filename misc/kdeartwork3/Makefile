# $NetBSD: Makefile,v 1.18 2004/01/03 18:49:47 reed Exp $

DISTNAME=	kdeartwork-3.1.4
PKGREVISION=	1
CATEGORIES=	misc
COMMENT=	Artwork for the KDE integrated X11 desktop
PKGREVISION=	2

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

DEPENDS+=	xscreensaver>=4.14:../../x11/xscreensaver

.include "../../mk/bsd.prefs.mk"

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
