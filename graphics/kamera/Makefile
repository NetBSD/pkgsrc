# $NetBSD: Makefile,v 1.81 2024/02/06 11:05:22 markd Exp $

DISTNAME=	kamera-${KAPPSVER}
CATEGORIES=	graphics

HOMEPAGE=	https://apps.kde.org/kamera/
COMMENT=	KDE digital camera manager
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
