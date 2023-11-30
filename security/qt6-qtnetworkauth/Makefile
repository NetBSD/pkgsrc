# $NetBSD: Makefile,v 1.11 2023/11/30 20:11:28 adam Exp $

DISTNAME=	qtnetworkauth-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtnetworkauth-${QTVERSION}
COMMENT=	Qt6 module with auth libraries
CATEGORIES=	security net
LICENSE=	gnu-gpl-v3

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6NetworkAuth.pc

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
