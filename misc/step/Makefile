# $NetBSD: Makefile,v 1.106 2026/02/06 10:05:24 wiz Exp $

DISTNAME=	step-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/applications/education/step/
COMMENT=	KDE interactive physical simulator
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge pkg-config

PYTHON_FOR_BUILD_ONLY=		yes
.include "../../lang/python/tool.mk"

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../graphics/kf6-kplotting/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/qalculate/buildlink3.mk"
.include "../../net/kf6-knewstuff/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
