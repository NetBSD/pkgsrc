# $NetBSD: Makefile,v 1.9 2023/11/30 20:11:27 adam Exp $

DISTNAME=	qtlocation-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtlocation-${QTVERSION}
COMMENT=	Qt6 location module
CATEGORIES=	geography
LICENSE=	gnu-gpl-v3 OR gnu-gpl-v2

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Location.pc

.include "../../geography/qt6-qtpositioning/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
