# $NetBSD: Makefile,v 1.25 2004/03/09 12:38:16 markd Exp $

DISTNAME=	kdegames-${_KDE_VERSION}
CATEGORIES=	games
COMMENT=	Games for the KDE integrated X11 desktop

DEPENDS+=	xdg-dirs>=1.1:../../misc/xdg-dirs

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
