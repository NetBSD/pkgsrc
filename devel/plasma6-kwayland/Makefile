# $NetBSD: Makefile,v 1.5 2024/11/14 22:19:34 wiz Exp $

DISTNAME=	kwayland-${PLASMAVER}
PKGREVISION=	3
CATEGORIES=	devel

HOMEPAGE=	https://invent.kde.org/plasma/kwayland
COMMENT=	Qt-style Client and Server library wrapper for the Wayland libraries
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/plasma6.mk"

TOOL_DEPENDS+=	plasma-wayland-protocols>=1.7:../../devel/plasma-wayland-protocols

USE_TOOLS+=	pkg-config

# Don't do autotests.  Some builds are linux specific.
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=no
CMAKE_CONFIGURE_ARGS+=	-DKF_IGNORE_PLATFORM_CHECK=true

.include "../../devel/wayland/platform.mk"
.if empty(PLATFORM_SUPPORTS_WAYLAND:M[Yy][Ee][Ss])
PKG_SKIP_REASON+=       "Platform does not support Wayland"
.endif

.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/qt6-qtwayland/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
