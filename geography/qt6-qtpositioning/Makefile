# $NetBSD: Makefile,v 1.4 2023/08/03 20:01:31 adam Exp $

DISTNAME=	qtpositioning-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtpositioning-${QTVERSION}
COMMENT=	Qt6 positioning module
CATEGORIES=	geography
LICENSE=	gnu-gpl-v3

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Positioning.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6PositioningQuick.pc

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/qt6-qtserialport/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
