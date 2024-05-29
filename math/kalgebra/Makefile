# $NetBSD: Makefile,v 1.81 2024/05/29 16:33:27 adam Exp $

DISTNAME=	kalgebra-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	math

HOMEPAGE=	https://kde.org/applications/education/kalgebra/
COMMENT=	KDE graph calculator
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../math/analitza/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
CMAKE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_Qt5WebEngineWidgets:BOOL=TRUE
#.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
