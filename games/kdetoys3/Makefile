# $NetBSD: Makefile,v 1.27 2004/10/13 12:56:29 markd Exp $

DISTNAME=	kdetoys-${_KDE_VERSION}
CATEGORIES=	games
COMMENT=	Toys for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
