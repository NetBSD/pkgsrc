# $NetBSD: Makefile,v 1.84 2026/09/02 19:01:33 wiz Exp $

DISTNAME=	kompare-${KAPPSVER}
PKGREVISION=	7
CATEGORIES=	devel

HOMEPAGE=	https://kde.org/applications/development/kompare/
COMMENT=	Diff/Patch Frontend
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/libkomparediff2/buildlink3.mk"
.include "../../devel/kf6-ktexteditor/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
