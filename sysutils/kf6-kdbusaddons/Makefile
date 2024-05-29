# $NetBSD: Makefile,v 1.2 2024/05/29 16:34:27 adam Exp $

DISTNAME=	kdbusaddons-${KF6VER}
PKGREVISION=	1
CATEGORIES=	sysutils

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Addons to QtDBus
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

.include "../../x11/qt6-qtbase/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt6-qttools= build
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
