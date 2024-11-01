# $NetBSD: Makefile,v 1.5 2024/11/01 00:52:49 wiz Exp $

DISTNAME=	kuserfeedback-1.3.0
PKGREVISION=	3
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
