# $NetBSD: Makefile,v 1.93 2023/04/03 20:21:22 nros Exp $

DISTNAME=	kdf-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	sysutils

HOMEPAGE=	https://apps.kde.org/kdf/
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
