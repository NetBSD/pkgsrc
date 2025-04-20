# $NetBSD: Makefile,v 1.89 2025/04/20 20:00:12 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}

COMMENT=	Python bindings for cairo

.include "Makefile.common"

TOOL_DEPENDS+=	${PYPKGPREFIX}-meson_python-[0-9]*:../../devel/py-meson_python

USE_TOOLS+=	pkg-config

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.13.1
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/py-cairo-shared/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
