# $NetBSD: Makefile,v 1.75 2026/01/07 08:46:32 wiz Exp $

DISTNAME=	kapptemplate-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	devel

HOMEPAGE=	https://kde.org/applications/development/kapptemplate/
COMMENT=	KDE Template Generator
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	gmake msgmerge

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kf6-kirigami/buildlink3.mk"
.include "../../x11/kirigami-addons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
