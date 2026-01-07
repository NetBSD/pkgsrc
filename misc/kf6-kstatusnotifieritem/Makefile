# $NetBSD: Makefile,v 1.6 2026/01/07 08:47:58 wiz Exp $

DISTNAME=	kstatusnotifieritem-${KF6VER}
PKGREVISION=	2
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Implementation of Status Notifier Items
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/kf6.mk"

CMAKE_CONFIGURE_ARGS+=	-DBUILD_PYTHON_BINDINGS=OFF

USE_TOOLS+=	pkg-config

.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../x11/kf6-kwindowsystem/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
