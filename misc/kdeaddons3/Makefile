# $NetBSD: Makefile,v 1.29 2004/10/13 12:44:10 markd Exp $

DISTNAME=	kdeaddons-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Add ons for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1

.include "../../mk/bsd.prefs.mk"

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../games/kdegames3/buildlink3.mk"
.include "../../misc/kdepim3/buildlink3.mk"
.include "../../multimedia/kdemultimedia3/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
