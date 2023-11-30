# $NetBSD: Makefile,v 1.11 2023/11/30 20:11:30 adam Exp $

DISTNAME=	qtwebsockets-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtwebsockets-${QTVERSION}
COMMENT=	Qt6 module for websockets communication
CATEGORIES=	net
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6WebSockets.pc

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
