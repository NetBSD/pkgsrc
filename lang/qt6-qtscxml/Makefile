# $NetBSD: Makefile,v 1.14 2024/05/29 16:33:17 adam Exp $

DISTNAME=	qtscxml-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtscxml-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt6 module for scxml language support
CATEGORIES=	lang devel
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v3

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Scxml.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6ScxmlQml.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6StateMachine.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6StateMachineQml.pc

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
