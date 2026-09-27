# $NetBSD: Makefile,v 1.95 2026/09/27 11:36:58 tnn Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2

COMMENT=	Python bindings for cairo

.include "Makefile.common"

TOOL_DEPENDS+=	${PYPKGPREFIX}-meson_python-[0-9]*:../../devel/py-meson_python

USE_TOOLS+=	pkg-config

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.13.1
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/py-cairo-shared/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
