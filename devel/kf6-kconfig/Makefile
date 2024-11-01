# $NetBSD: Makefile,v 1.4 2024/11/01 00:51:23 wiz Exp $

DISTNAME=	kconfig-${KF6VER}
PKGREVISION=	2
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Configuration system
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=OFF

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
