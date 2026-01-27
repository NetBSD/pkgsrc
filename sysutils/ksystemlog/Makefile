# $NetBSD: Makefile,v 1.74 2026/01/27 08:40:36 wiz Exp $

DISTNAME=	ksystemlog-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	sysutils

HOMEPAGE=	https://kde.org/applications/system/ksystemlog/
COMMENT=	System log viewer tool
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
