# $NetBSD: Makefile,v 1.36 2026/09/27 11:37:00 tnn Exp $

DISTNAME=	qtdatavis3d-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtdatavis3d-${QTVERSION}
PKGREVISION=	2
COMMENT=	Qt6 module for data visualization
CATEGORIES=	graphics

LICENSE=	gnu-gpl-v3

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6DataVisualization.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6DataVisualizationQml.pc

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../multimedia/qt6-qtmultimedia/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
