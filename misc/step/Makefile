# $NetBSD: Makefile,v 1.72 2022/08/11 05:09:04 gutteridge Exp $

DISTNAME=	step-${KAPPSVER}
PKGREVISION=	11
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/applications/education/step/
COMMENT=	KDE interactive physical simulator
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		yes
.include "../../lang/python/tool.mk"

.include "../../graphics/kplotting/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/qalculate/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/khtml/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
