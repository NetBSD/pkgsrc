# $NetBSD: Makefile,v 1.80 2024/02/06 11:17:36 markd Exp $

DISTNAME=	kmousetool-${KAPPSVER}
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/applications/utilities/kmousetool/
COMMENT=	KDE mouse manipulation tool
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/knotifications/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
