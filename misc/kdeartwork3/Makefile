# $NetBSD: Makefile,v 1.13 2003/07/30 14:11:59 markd Exp $

DISTNAME=	kdeartwork-3.1.3
CATEGORIES=	misc
COMMENT=	Artwork for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

DEPENDS+=	{xscreensaver>=4.06,xscreensaver-gnome>=4.06}:../../x11/xscreensaver

.include "../../mk/bsd.prefs.mk"

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
