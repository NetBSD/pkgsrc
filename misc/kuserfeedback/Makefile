# $NetBSD: Makefile,v 1.4 2024/05/29 16:33:37 adam Exp $

DISTNAME=	kuserfeedback-1.3.0
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_KDE:=kuserfeedback/}

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Collecting user feedback for applications via telemetry and surveys
LICENSE=	mit

.include "../../meta-pkgs/kde/applications.mk"

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtcharts/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
