# $NetBSD: Makefile,v 1.14 2024/11/14 22:18:56 wiz Exp $

DISTNAME=	qtconnectivity-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtconnectivity-${QTVERSION}
PKGREVISION=	3
COMMENT=	Qt6 connectivity
CATEGORIES=	comms

LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Bluetooth.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Nfc.pc

.if ${OPSYS} != "Darwin"
PLIST_SRC= PLIST PLIST.dummy
.endif

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
