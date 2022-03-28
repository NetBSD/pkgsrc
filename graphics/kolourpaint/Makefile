# $NetBSD: Makefile,v 1.63 2022/03/28 10:44:23 tnn Exp $

DISTNAME=	kolourpaint-${KAPPSVER}
PKGREVISION=	6
CATEGORIES=	graphics

HOMEPAGE=	https://kde.org/applications/graphics/kolourpaint/
COMMENT=	KDE paint program
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/kio/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libksane/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
