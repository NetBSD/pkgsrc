# $NetBSD: Makefile,v 1.122 2026/09/27 11:37:43 tnn Exp $

DISTNAME=	rocs-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/applications/education/rocs/
COMMENT=	KDE graph theory IDE
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

# Boost tests to many things that aren defined
BUILDLINK_TRANSFORM+=	rm:-Werror=undef

.include "../../archivers/kf6-karchive/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/kf6-kdeclarative/buildlink3.mk"
.include "../../devel/kf6-ktexteditor/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/kf6-ktexttemplate/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
