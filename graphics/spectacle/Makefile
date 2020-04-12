# $NetBSD: Makefile,v 1.6 2020/04/12 08:28:51 adam Exp $

DISTNAME=	spectacle-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	graphics

HOMEPAGE=	https://kde.org/applications/graphics/kruler/
COMMENT=	KDE screenshot capture utility
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2 AND gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/kdeclarative/buildlink3.mk"
.include "../../devel/kwayland/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
