# $NetBSD: Makefile,v 1.20 2004/02/04 23:02:05 markd Exp $

DISTNAME=	kdeaddons-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Add ons for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

.include "../../mk/bsd.prefs.mk"

.include "../../games/kdegames3/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../misc/kdepim3/buildlink2.mk"
.include "../../multimedia/kdemultimedia3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
