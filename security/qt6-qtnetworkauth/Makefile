# $NetBSD: Makefile,v 1.14 2024/05/29 16:34:20 adam Exp $

DISTNAME=	qtnetworkauth-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtnetworkauth-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt6 module with auth libraries
CATEGORIES=	security net
LICENSE=	gnu-gpl-v3

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6NetworkAuth.pc

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
