# $NetBSD: Makefile,v 1.25 2004/04/05 18:41:14 wiz Exp $

DISTNAME=	kdeaddons-${_KDE_VERSION}
PKGREVISION=	2
CATEGORIES=	misc
COMMENT=	Add ons for the KDE integrated X11 desktop

DEPENDS+=	xdg-dirs>=1.1:../../misc/xdg-dirs

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

.include "../../mk/bsd.prefs.mk"

.include "../../games/kdegames3/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../misc/kdepim3/buildlink2.mk"
.include "../../multimedia/kdemultimedia3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
