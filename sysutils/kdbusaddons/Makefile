# $NetBSD: Makefile,v 1.57 2023/04/03 20:21:21 nros Exp $

DISTNAME=	kdbusaddons-${KF5VER}
PKGREVISION=	3
CATEGORIES=	sysutils

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Addons to QtDBus
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
