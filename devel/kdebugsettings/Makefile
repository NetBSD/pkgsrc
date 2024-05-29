# $NetBSD: Makefile,v 1.8 2024/05/29 16:32:05 adam Exp $

DISTNAME=	kdebugsettings-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	devel

HOMEPAGE=	https://utils.kde.org/
COMMENT=	Application to enable/disable qCDebug
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../sysutils/kdbusaddons/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/kcompletion/buildlink3.mk"
.include "../../x11/kitemviews/buildlink3.mk"
.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
