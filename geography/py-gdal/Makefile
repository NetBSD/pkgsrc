# $NetBSD: Makefile,v 1.68 2024/05/23 14:19:07 gdt Exp $

PKGREVISION= 2
.include "../../geography/gdal-lib/Makefile.common"
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
#PKGREVISION=	0

COMMENT=	Translator library for raster geospatial data formats, Python binding

# Beause this package runs cmake for all of gdal, everything that is
# hard-required must be present, separately from whether it is needed
# for the python bindings.
USE_LANGUAGES=		c c++
USE_CC_FEATURES+=	c99
USE_CXX_FEATURES+=	c++11

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../mk/bsd.prefs.mk"

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel

WHEEL_NAME=		GDAL-${PKGVERSION_NOREV}
PYSETUPSUBDIR=		build/swig/python

# Upstream's distfile does not have a ready-to-use python module
# source directory.  Creating it requires cmake, but apparently not
# building the rest of gdal.
#   \todo Consider enhancing cmake support to allow configure-only and
#   not overriding the rest of the targets while allowing use of
#   wheel's build/install targets.
TOOL_DEPENDS+=	cmake>=0:../../devel/cmake
TOOL_DEPENDS+=	swig4-[0-9]*:../../devel/swig4
pre-build:
	cd ${WRKSRC} && mkdir build && cd build && \
	cmake .. && \
	cd swig/python && \
	${MAKE} python_generated_files

BUILDLINK_API_DEPENDS.gdal-lib+=	gdal-lib>=3.9.0
.include "../../geography/gdal-lib/buildlink3.mk"
# \todo Explain why wheel must be before tool (Python.h not found), or fix
# documentation of python/foo.mk.
.include "../../lang/python/wheel.mk"
.include "../../lang/python/tool.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
