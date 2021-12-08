# $NetBSD: Makefile,v 1.34 2021/12/08 16:04:59 adam Exp $

DISTNAME=	kimageformats-${KF5VER}
PKGREVISION=	4
CATEGORIES=	graphics

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Image format plugins for Qt5
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	pkg-config

# C++14 (openexr)
GCC_REQD+=	6

.include "../../archivers/karchive/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
