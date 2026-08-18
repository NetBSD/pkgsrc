# $NetBSD: Makefile,v 1.30 2026/08/18 18:26:05 adam Exp $

DISTNAME=	qtshadertools-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtshadertools-${QTVERSION}
COMMENT=	Qt6 shadertools
CATEGORIES=	graphics
LICENSE=	gnu-gpl-v3

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6ShaderTools.pc

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
