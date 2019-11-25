# $NetBSD: Makefile,v 1.43 2019/11/25 10:13:48 markd Exp $

DISTNAME=	kmousetool-${KAPPSVER}
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/applications/utilities/kmousetool/
COMMENT=	KDE mouse manipulation tool
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=${KF5VER}:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/knotifications/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
