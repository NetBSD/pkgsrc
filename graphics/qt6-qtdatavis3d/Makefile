# $NetBSD: Makefile,v 1.2 2023/01/29 21:14:44 ryoon Exp $

DISTNAME=	qtdatavis3d-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtdatavis3d-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt6 module for data visualization
CATEGORIES=	graphics

LICENSE=	gnu-gpl-v3

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6DataVisualization.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6DataVisualizationQml.pc

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
