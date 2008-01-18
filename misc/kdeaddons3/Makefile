# $NetBSD: Makefile,v 1.57 2008/01/18 05:08:35 tnn Exp $

DISTNAME=	kdeaddons-${_KDE_VERSION}
PKGREVISION=	2
CATEGORIES=	misc
COMMENT=	Add ons for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

REPLACE_PERL+=		knewsticker-scripts/bbc.pl \
			knewsticker-scripts/newsrss.pl \
			knewsticker-scripts/stock.pl

.include "../../mk/bsd.prefs.mk"

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../games/kdegames3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kdepim3/buildlink3.mk"
.include "../../multimedia/kdemultimedia3/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
