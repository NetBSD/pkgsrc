# $NetBSD: Makefile,v 1.12 2003/07/13 13:52:41 wiz Exp $

DISTNAME=	kdeartwork-3.1.2
PKGREVISION=	1
CATEGORIES=	misc
COMMENT=	Artwork for the KDE integrated X11 desktop

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

DEPENDS+=	{xscreensaver>=4.06,xscreensaver-gnome>=4.06}:../../x11/xscreensaver

.include "../../mk/bsd.prefs.mk"

.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
