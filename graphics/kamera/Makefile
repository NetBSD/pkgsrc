# $NetBSD: Makefile,v 1.64 2022/08/11 05:08:43 gutteridge Exp $

DISTNAME=	kamera-${KAPPSVER}
PKGREVISION=	8
CATEGORIES=	graphics

HOMEPAGE=	https://kde.org/applications/graphics/kamera/
COMMENT=	KDE digital camera manager
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
