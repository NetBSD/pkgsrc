# $NetBSD: Makefile,v 1.37 2006/01/24 07:32:23 wiz Exp $

DISTNAME=	kdeaddons-${_KDE_VERSION}
PKGREVISION=	2
CATEGORIES=	misc
COMMENT=	Add ons for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_DIRS+=		xdg-1.1

REPLACE_PERL=		knewsticker-scripts/bbc.pl \
			knewsticker-scripts/newsrss.pl \
			knewsticker-scripts/stock.pl

.include "../../mk/bsd.prefs.mk"

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../games/kdegames3/buildlink3.mk"
.include "../../misc/kdepim3/buildlink3.mk"
.include "../../multimedia/kdemultimedia3/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
