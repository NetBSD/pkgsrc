# $NetBSD: Makefile,v 1.26 2004/04/14 16:15:25 jmmv Exp $

DISTNAME=	kdeaddons-${_KDE_VERSION}
PKGREVISION=	2
CATEGORIES=	misc
COMMENT=	Add ons for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES
USE_DIRS+=		xdg-1.1

.include "../../mk/bsd.prefs.mk"

.include "../../games/kdegames3/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../misc/kdepim3/buildlink2.mk"
.include "../../multimedia/kdemultimedia3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
