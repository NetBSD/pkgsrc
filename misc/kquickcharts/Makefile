# $NetBSD: Makefile,v 1.14 2024/02/06 10:46:29 markd Exp $

DISTNAME=	kquickcharts-${KF5VER}
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	QtQuick plugin providing high-performance charts
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	msgmerge

.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
