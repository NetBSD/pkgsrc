# $NetBSD: Makefile,v 1.11 2025/04/24 14:14:26 wiz Exp $

DISTNAME=	kimageformats-${KF6VER}
PKGREVISION=	3
CATEGORIES=	graphics

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Image format plugins for Qt5
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	pkg-config

.include "../../archivers/kf6-karchive/buildlink3.mk"
.include "../../graphics/libavif/buildlink3.mk"
.include "../../graphics/libraw/buildlink3.mk"
.include "../../graphics/libjxl/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
