# $NetBSD: Makefile,v 1.31 2019/11/18 10:05:35 markd Exp $

DISTNAME=	klickety-${KAPPSVER}
CATEGORIES=	games

HOMEPAGE=	https://kde.org/applications/games/klickety/
COMMENT=	Strategy game for KDE, an adaption of the Clickomania game
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=${KF5VER}:../../devel/kdoctools

USE_TOOLS+=	msgmerge

REPLACE_PERL+=	klickety-2.0-inherit-ksame-highscore.pl

.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
