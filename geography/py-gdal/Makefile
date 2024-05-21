# $NetBSD: Makefile,v 1.65 2024/05/21 18:21:33 gdt Exp $

PKGREVISION=	10
.include "../../geography/gdal-lib/Makefile.common"
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
#PKGREVISION=	0

COMMENT=	Translator library for raster geospatial data formats, Python binding

USE_LANGUAGES=		c c++
USE_C_FEATURES+=	c99
USE_CXX_FEATURES+=	c++11

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

PYSETUPSUBDIR=		swig/python

.include "../../mk/bsd.prefs.mk"

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel

.include "../../geography/gdal-lib/buildlink3.mk"
# \todo Explain why wheel must be before tool (Python.h not found), or fix
# documentation of python/foo.mk.
.include "../../lang/python/wheel.mk"
.include "../../lang/python/tool.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
