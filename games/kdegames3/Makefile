# $NetBSD: Makefile,v 1.27 2004/04/14 16:15:23 jmmv Exp $

DISTNAME=	kdegames-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	games
COMMENT=	Games for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES
USE_DIRS+=		xdg-1.1

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
