# $NetBSD: Makefile,v 1.71 2013/02/09 22:11:40 ryoon Exp $

DISTNAME=	kdeartwork-${_KDE_VERSION}
PKGREVISION=	20
CATEGORIES=	misc
COMMENT=	Artwork for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

DEPENDS+=	xscreensaver>=5.10:../../x11/xscreensaver

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
