# $NetBSD: Makefile,v 1.12 2024/05/29 16:32:48 adam Exp $

DISTNAME=	qtlocation-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtlocation-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt6 location module
CATEGORIES=	geography
LICENSE=	gnu-gpl-v3 OR gnu-gpl-v2

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Location.pc

.include "../../geography/qt6-qtpositioning/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
