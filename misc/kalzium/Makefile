# $NetBSD: Makefile,v 1.68 2022/07/02 16:53:26 ryoon Exp $

DISTNAME=	kalzium-${KAPPSVER}
PKGREVISION=	7
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/applications/education/kalzium/
COMMENT=	Periodic table of elements
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/kplotting/buildlink3.mk"
#include "../../lang/ocaml/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../misc/kunitconversion/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/khtml/buildlink3.mk"
.include "../../x11/kwidgetsaddons/buildlink3.mk"
.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
