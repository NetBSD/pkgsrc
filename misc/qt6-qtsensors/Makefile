# $NetBSD: Makefile,v 1.9 2024/05/29 16:33:39 adam Exp $

DISTNAME=	qtsensors-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtsensors-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt6 sensors
CATEGORIES=	misc

LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Sensors.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6SensorsQuick.pc

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
