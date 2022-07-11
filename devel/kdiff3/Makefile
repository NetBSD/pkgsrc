# $NetBSD: Makefile,v 1.85 2022/07/11 00:13:19 gutteridge Exp $

DISTNAME=	kdiff3-1.9.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_KDE:=kdiff3/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kde.org/applications/development/org.kde.kdiff3
COMMENT=	File and directory diff and merge tool
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++17
GCC_REQD+=	7 # C++17

BUILDLINK_TRANSFORM+=	rm:-Wl,--fatal-warnings

BUILD_DEPENDS+=		extra-cmake-modules>=5.10.0:../../devel/extra-cmake-modules
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
