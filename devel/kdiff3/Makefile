# $NetBSD: Makefile,v 1.114 2025/02/07 09:24:31 wiz Exp $

DISTNAME=	kdiff3-1.12.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_KDE:=kdiff3/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kde.org/applications/development/org.kde.kdiff3
COMMENT=	File and directory diff and merge tool
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
# upstream states GCC < 9.2 support is "best effort only"
USE_CXX_FEATURES+=	c++17
CMAKE_REQD+=		3.1

BUILDLINK_TRANSFORM+=	rm:-Wl,--fatal-warnings

.include "../../devel/cmake/build.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-kcrash/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/qt6-qt5compat/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
