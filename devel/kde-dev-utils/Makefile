# $NetBSD: Makefile,v 1.74 2025/12/21 10:12:10 markd Exp $

DISTNAME=	kde-dev-utils-${KAPPSVER}
CATEGORIES=	devel

HOMEPAGE=	https://kde.org/applications/development/
COMMENT=	Small utilities for developers using KDE/Qt libs/frameworks
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-kparts/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
