# $NetBSD: Makefile,v 1.5 2023/10/24 22:09:21 wiz Exp $

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
