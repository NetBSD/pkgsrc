# $NetBSD: Makefile,v 1.7 2026/09/02 19:03:31 wiz Exp $

DISTNAME=	kuserfeedback-${KF6VER}
PKGREVISION=	2
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Collecting user feedback for applications via telemetry and surveys
LICENSE=	mit

.include "../../meta-pkgs/kde/kf6.mk"

.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../graphics/qt6-qtcharts/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
