# $NetBSD: Makefile,v 1.38 2020/11/05 09:06:47 ryoon Exp $

DISTNAME=	kconfig-${KF5VER}
PKGREVISION=	3
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Configuration system
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
