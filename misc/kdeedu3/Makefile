# $NetBSD: Makefile,v 1.38 2006/01/31 22:39:29 markd Exp $

DISTNAME=	kdeedu-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Edu{tainment,cation} tools for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

REPLACE_PERL=	\
	kvoctrain/kvoctrain/langen2kvtml \
	kvoctrain/kvoctrain/spotlight2kvtml

USE_DIRS+=		xdg-1.1

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
