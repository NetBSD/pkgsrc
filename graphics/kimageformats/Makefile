# $NetBSD: Makefile,v 1.69 2026/09/02 19:02:44 wiz Exp $

DISTNAME=	kimageformats-${KF5VER}
PKGREVISION=	16
CATEGORIES=	graphics

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Image format plugins for Qt5
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	pkg-config

# C++14 (openexr)
GCC_REQD+=	6

.include "../../archivers/karchive/buildlink3.mk"
.include "../../graphics/libavif/buildlink3.mk"
.include "../../graphics/libraw/buildlink3.mk"
.include "../../graphics/libjxl/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
