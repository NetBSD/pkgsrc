# $NetBSD: Makefile,v 1.2 2024/05/29 16:34:27 adam Exp $

DISTNAME=	solid-${KF6VER}
PKGREVISION=	1
CATEGORIES=	sysutils

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Hardware integration and detection
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	flex bison

.include "options.mk"
BUILDLINK_DEPMETHOD.qt6-qttools= build
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
