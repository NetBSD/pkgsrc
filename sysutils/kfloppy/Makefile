# $NetBSD: Makefile,v 1.63 2022/08/11 05:09:16 gutteridge Exp $

DISTNAME=	kfloppy-${KAPPSVER}
PKGREVISION=	8
CATEGORIES=	sysutils

HOMEPAGE=	https://kde.org/applications/utilities/kfloppy/
COMMENT=	KDE floppy formatter
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
