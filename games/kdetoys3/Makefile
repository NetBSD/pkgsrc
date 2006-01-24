# $NetBSD: Makefile,v 1.30 2006/01/24 07:32:09 wiz Exp $

DISTNAME=	kdetoys-${_KDE_VERSION}
PKGREVISION=	2
CATEGORIES=	games
COMMENT=	Toys for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_DIRS+=		xdg-1.1

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
