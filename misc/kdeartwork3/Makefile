# $NetBSD: Makefile,v 1.14 2003/08/05 13:39:01 drochner Exp $

DISTNAME=	kdeartwork-3.1.3
PKGREVISION=	1
CATEGORIES=	misc
COMMENT=	Artwork for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

DEPENDS+=	{xscreensaver>=4.06,xscreensaver-gnome>=4.06}:../../x11/xscreensaver

.include "../../mk/bsd.prefs.mk"

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
