# $NetBSD: Makefile,v 1.97 2026/01/07 08:47:56 wiz Exp $

DISTNAME=	kalzium-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/applications/education/kalzium/
COMMENT=	Periodic table of elements
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=5.19.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/qt6-qt5compat/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/kf6-kplotting/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/qt6-qtscxml/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../misc/kf6-kunitconversion/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
