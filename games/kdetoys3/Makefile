# $NetBSD: Makefile,v 1.59 2012/09/15 10:04:41 obache Exp $

DISTNAME=	kdetoys-${_KDE_VERSION}
PKGREVISION=	15
CATEGORIES=	games
COMMENT=	Toys for the KDE integrated X11 desktop

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

.include "../../meta-pkgs/kde3/Makefile.kde3"

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
