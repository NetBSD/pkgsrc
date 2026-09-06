# $NetBSD: Makefile,v 1.125 2026/09/06 11:03:06 markd Exp $

DISTNAME=	filelight-${KAPPSVER}
CATEGORIES=	sysutils

HOMEPAGE=	https://kde.org/applications/utilities/org.kde.filelight/
COMMENT=	Graphical filesystem usage monitor
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools
DEPENDS+=	kf6-qqc2-desktop-style>=6.18.0:../../x11/kf6-qqc2-desktop-style

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-kdeclarative/buildlink3.mk"
.include "../../devel/kf6-kparts/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
