# $NetBSD: Makefile,v 1.69 2024/02/06 11:05:17 markd Exp $

DISTNAME=	katomic-${KAPPSVER}
CATEGORIES=	games

HOMEPAGE=	https://kde.org/applications/games/katomic/
COMMENT=	Build complex atoms with a minimal amount of moves
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

REPLACE_PERL+=	src/katomic-levelset-upd.pl

.include "../../games/libkdegames/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
