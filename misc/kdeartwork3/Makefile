# $NetBSD: Makefile,v 1.16 2003/12/08 14:41:40 wiz Exp $

DISTNAME=	kdeartwork-3.1.4
CATEGORIES=	misc
COMMENT=	Artwork for the KDE integrated X11 desktop
PKGREVISION=	1

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

DEPENDS+=	{xscreensaver>=4.06,xscreensaver-gnome>=4.06}:../../x11/xscreensaver

.include "../../mk/bsd.prefs.mk"

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
