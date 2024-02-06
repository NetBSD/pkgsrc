# $NetBSD: Makefile,v 1.1 2024/02/06 02:58:48 markd Exp $

DISTNAME=	kuserfeedback-1.3.0
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
.include "../../mk/bsd.pkg.mk"
