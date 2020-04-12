# $NetBSD: Makefile,v 1.70 2020/04/12 08:29:13 adam Exp $

DISTNAME=	kdf-${KAPPSVER}
PKGREVISION=	3
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
