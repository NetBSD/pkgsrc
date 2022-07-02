# $NetBSD: Makefile,v 1.53 2022/07/02 16:53:19 ryoon Exp $

DISTNAME=	kpat-${KAPPSVER}
PKGREVISION=	7
CATEGORIES=	games

HOMEPAGE=	https://kde.org/applications/games/kpat/
COMMENT=	Multiplicity of different solitaire games
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

.include "../../games/black-hole-solver/buildlink3.mk"
.include "../../games/freecell-solver/buildlink3.mk"
.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
