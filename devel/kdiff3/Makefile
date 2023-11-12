# $NetBSD: Makefile,v 1.103 2023/11/12 13:21:01 wiz Exp $

DISTNAME=	kdiff3-1.10.6
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_KDE:=kdiff3/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kde.org/applications/development/org.kde.kdiff3
COMMENT=	File and directory diff and merge tool
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++17

BUILDLINK_TRANSFORM+=	rm:-Wl,--fatal-warnings

TOOL_DEPENDS+=		extra-cmake-modules>=5.10.0:../../devel/extra-cmake-modules
TOOLS_DEPENDS.cmake=	cmake>=3.1:../../devel/cmake

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.kcoreaddons+=	kcoreaddons>=5.80.0
.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../devel/kcrash/buildlink3.mk"
.include "../../devel/kdoctools/buildlink3.mk"
BUILDLINK_API_DEPENDS.ki18n+=	ki18n>=5.80.0
.include "../../devel/ki18n/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../devel/kparts/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/kiconthemes/buildlink3.mk"
.include "../../x11/kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
