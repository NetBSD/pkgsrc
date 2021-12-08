# $NetBSD: Makefile,v 1.83 2021/12/08 16:06:32 adam Exp $

DISTNAME=	kdf-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	sysutils

HOMEPAGE=	https://kde.org/applications/system/kdiskfree/
COMMENT=	Show mount points and disk usage under KDE desktop
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
