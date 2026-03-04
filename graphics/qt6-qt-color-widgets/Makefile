# $NetBSD: Makefile,v 1.2 2026/03/04 00:20:26 tnn Exp $

DISTNAME=	Qt-Color-Widgets-3.0.0
PKGNAME=	${DISTNAME:S/Qt-Color-Widgets/qt6-qt-color-widgets/}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITLAB:=mattbas/}
GITLAB_PROJECT=	Qt-Color-Widgets
GITLAB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/mattbas/Qt-Color-Widgets/
COMMENT=	Color dialog for Qt-based applications
LICENSE=	gnu-lgpl-v3

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c++
CMAKE_CONFIGURE_ARGS+=	-DQT_VERSION_MAJOR=6
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON

PKGCONFIG_OVERRIDE+=	QtColorWidgets.pc.in

.include "../../devel/cmake/build.mk"
BUILDLINK_DEPMETHOD.qt6-qttools=	build
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
