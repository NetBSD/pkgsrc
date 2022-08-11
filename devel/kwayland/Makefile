# $NetBSD: Makefile,v 1.17 2022/08/11 05:08:11 gutteridge Exp $

DISTNAME=	kwayland-${KF5VER}
PKGREVISION=	1
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Qt-style Client and Server library wrapper for the Wayland libraries
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

BUILD_DEPENDS+=	plasma-wayland-protocols>=1.4:../../devel/plasma-wayland-protocols

USE_TOOLS+=	pkg-config
# Don't do autotests.  Some builds are linux specific.
CMAKE_ARGS+=	-DBUILD_TESTING=no

.include "../../devel/wayland/platform.mk"

.if empty(PLATFORM_SUPPORTS_WAYLAND:M[Yy][Ee][Ss])
PKG_SKIP_REASON+=	"Platform does not support Wayland"
.endif

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwayland/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

