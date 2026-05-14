# $NetBSD: Makefile,v 1.8 2026/05/14 16:41:32 ryoon Exp $

DISTNAME=	kstatusnotifieritem-${KF6VER}
PKGREVISION=	4
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
