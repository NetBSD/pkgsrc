# $NetBSD: Makefile,v 1.46 2022/08/11 05:09:02 gutteridge Exp $

DISTNAME=	kteatime-${KAPPSVER}
PKGREVISION=	8
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/applications/games/kteatime/
COMMENT=	KDE Tea Cooker
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v3 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
