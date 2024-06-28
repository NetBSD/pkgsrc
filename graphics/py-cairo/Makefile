# $NetBSD: Makefile,v 1.87 2024/06/28 17:16:47 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}

COMMENT=	Python bindings for cairo

.include "Makefile.common"

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.13.1
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/py-cairo-shared/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
