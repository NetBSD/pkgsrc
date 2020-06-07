# $NetBSD: Makefile,v 1.8 2020/06/07 11:27:01 markd Exp $

DISTNAME=	kwayland-${KF5VER}
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Qt-style Client and Server library wrapper for the Wayland libraries
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	pkg-config
# Don't do autotests.  Some builds are linux specific.
CMAKE_ARGS+=	-DBUILD_TESTING=no

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwayland/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

