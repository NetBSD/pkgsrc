# $NetBSD: Makefile,v 1.1 2024/05/26 11:22:13 markd Exp $

DISTNAME=	kconfig-${KF6VER}
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Configuration system
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

CMAKE_ARGS+=	-DBUILD_TESTING=OFF

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
