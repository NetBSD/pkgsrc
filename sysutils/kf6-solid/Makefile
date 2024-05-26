# $NetBSD: Makefile,v 1.1 2024/05/26 13:00:35 markd Exp $

DISTNAME=	solid-${KF6VER}
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
