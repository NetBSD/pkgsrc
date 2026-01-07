# $NetBSD: Makefile,v 1.92 2026/01/07 08:47:52 wiz Exp $

DISTNAME=	kalgebra-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	math

HOMEPAGE=	https://kde.org/applications/education/kalgebra/
COMMENT=	KDE graph calculator
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../math/analitza/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Qt6WebEngineWidgets:BOOL=TRUE
#.include "../../www/qt6-qtwebengine/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
