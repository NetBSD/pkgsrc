# $NetBSD: Makefile,v 1.21 2004/03/08 19:40:39 jmmv Exp $

DISTNAME=	kdetoys-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	games
COMMENT=	Toys for the KDE integrated X11 desktop

DEPENDS+=	xdg-dirs>=1.1:../../misc/xdg-dirs

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
