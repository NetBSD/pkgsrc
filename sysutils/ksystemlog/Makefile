# $NetBSD: Makefile,v 1.63 2024/05/29 16:34:27 adam Exp $

DISTNAME=	ksystemlog-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	sysutils

HOMEPAGE=	https://kde.org/applications/system/ksystemlog/
COMMENT=	System log viewer tool
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/kio/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
