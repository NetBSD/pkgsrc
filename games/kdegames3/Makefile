# $NetBSD: Makefile,v 1.30 2004/10/13 12:54:56 markd Exp $

DISTNAME=	kdegames-${_KDE_VERSION}
CATEGORIES=	games
COMMENT=	Games for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
