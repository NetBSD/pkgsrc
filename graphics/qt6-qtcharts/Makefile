# $NetBSD: Makefile,v 1.14 2024/05/20 19:38:25 adam Exp $

DISTNAME=	qtcharts-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtcharts-${QTVERSION}
COMMENT=	Qt6 module for visualising data as charts
CATEGORIES=	graphics

LICENSE=	gnu-gpl-v3

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Charts.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6ChartsQml.pc

.include "../../x11/qt6-qtbase/Makefile.common"

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../multimedia/qt6-qtmultimedia/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
