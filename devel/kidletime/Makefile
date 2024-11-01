# $NetBSD: Makefile,v 1.48 2024/11/01 12:52:12 wiz Exp $

DISTNAME=	kidletime-${KF5VER}
PKGREVISION=	2
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Monitoring user activity
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	pkg-config

.include "../../devel/plasma-wayland-protocols/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwayland/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
