# $NetBSD: Makefile,v 1.105 2024/05/29 16:34:26 adam Exp $

DISTNAME=	kdf-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	sysutils

HOMEPAGE=	https://apps.kde.org/kdf/
COMMENT=	Show mount points and disk usage under KDE desktop
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
