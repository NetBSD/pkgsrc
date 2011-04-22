# $NetBSD: Makefile,v 1.60 2011/04/22 13:44:11 obache Exp $

DISTNAME=	kdeartwork-${_KDE_VERSION}
PKGREVISION=	10
CATEGORIES=	misc
COMMENT=	Artwork for the KDE integrated X11 desktop

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/kde3/Makefile.kde3"

DEPENDS+=	xscreensaver>=5.10:../../x11/xscreensaver

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
