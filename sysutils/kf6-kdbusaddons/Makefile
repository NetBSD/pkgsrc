# $NetBSD: Makefile,v 1.1 2024/05/26 12:54:23 markd Exp $

DISTNAME=	kdbusaddons-${KF6VER}
CATEGORIES=	sysutils

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Addons to QtDBus
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

.include "../../x11/qt6-qtbase/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt6-qttools= build
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
