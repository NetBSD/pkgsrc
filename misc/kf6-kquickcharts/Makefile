# $NetBSD: Makefile,v 1.2 2024/05/29 16:33:34 adam Exp $

DISTNAME=	kquickcharts-${KF6VER}
PKGREVISION=	1
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	QtQuick plugin providing high-performance charts
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	msgmerge

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
