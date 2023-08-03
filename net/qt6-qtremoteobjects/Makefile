# $NetBSD: Makefile,v 1.6 2023/08/03 20:01:32 adam Exp $

DISTNAME=	qtremoteobjects-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtremoteobjects-${QTVERSION}
COMMENT=	Qt6 module for easier IPC
CATEGORIES=	net
LICENSE=	gnu-lgpl-v3 OR gnu-lgpl-v2 OR gnu-gpl-v3

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6RemoteObjects.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6RemoteObjectsQml.pc

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
