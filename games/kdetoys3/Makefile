# $NetBSD: Makefile,v 1.55 2012/02/06 12:40:12 wiz Exp $

DISTNAME=	kdetoys-${_KDE_VERSION}
PKGREVISION=	11
CATEGORIES=	games
COMMENT=	Toys for the KDE integrated X11 desktop

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

.include "../../meta-pkgs/kde3/Makefile.kde3"

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
