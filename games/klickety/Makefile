# $NetBSD: Makefile,v 1.52 2022/07/02 16:53:18 ryoon Exp $

DISTNAME=	klickety-${KAPPSVER}
PKGREVISION=	7
CATEGORIES=	games

HOMEPAGE=	https://kde.org/applications/games/klickety/
COMMENT=	Strategy game for KDE, an adaption of the Clickomania game
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

REPLACE_PERL+=	klickety-2.0-inherit-ksame-highscore.pl

.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
