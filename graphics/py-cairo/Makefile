# $NetBSD: Makefile,v 1.88 2024/09/13 08:24:44 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}

COMMENT=	Python bindings for cairo

.include "Makefile.common"

TOOL_DEPENDS+=	${PYPKGPREFIX}-meson_python-[0-9]*:../../devel/py-meson_python

USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.13.1
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/py-cairo-shared/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
