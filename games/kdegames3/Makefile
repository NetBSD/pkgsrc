# $NetBSD: Makefile,v 1.17 2003/08/05 13:38:01 drochner Exp $

DISTNAME=	kdegames-3.1.3
PKGREVISION=	1
CATEGORIES=	games
COMMENT=	Games for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

FOO_MAIN_FILES= \
	kbackgammon/kbackgammon_main.cpp

.include "../../meta-pkgs/kde3/Makefile.foo_main"

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
