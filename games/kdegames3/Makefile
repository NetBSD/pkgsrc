# $NetBSD: Makefile,v 1.13 2003/05/02 11:55:00 wiz Exp $

DISTNAME=	kdegames-3.1.1
PKGREVISION=	1
CATEGORIES=	games
COMMENT=	Games for the KDE integrated X11 desktop

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

FOO_MAIN_FILES= \
	kbackgammon/kbackgammon_main.cpp

.include "../../x11/kde3/Makefile.foo_main"

.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
