# $NetBSD: Makefile,v 1.3 2024/06/15 06:22:40 jperkin Exp $

DISTNAME=	solid-${KF6VER}
PKGREVISION=	1
CATEGORIES=	sysutils

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Hardware integration and detection
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	flex bison

.include "options.mk"

.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
