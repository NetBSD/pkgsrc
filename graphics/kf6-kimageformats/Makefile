# $NetBSD: Makefile,v 1.2 2024/05/29 16:32:56 adam Exp $

DISTNAME=	kimageformats-${KF6VER}
PKGREVISION=	1
CATEGORIES=	graphics

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Image format plugins for Qt5
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	pkg-config

# C++14 (openexr)
GCC_REQD+=	6

.include "../../archivers/kf6-karchive/buildlink3.mk"
.include "../../graphics/libraw/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
