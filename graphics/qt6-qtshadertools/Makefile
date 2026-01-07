# $NetBSD: Makefile,v 1.25 2026/01/07 08:47:27 wiz Exp $

DISTNAME=	qtshadertools-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtshadertools-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt6 shadertools
CATEGORIES=	graphics
LICENSE=	gnu-gpl-v3

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6ShaderTools.pc

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
