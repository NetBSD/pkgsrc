# $NetBSD: Makefile,v 1.64 2024/05/21 13:36:10 gdt Exp $

PKGREVISION= 9
.include "../../geography/gdal-lib/Makefile.common"
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
#PKGREVISION=	0

COMMENT=	Translator library for raster geospatial data formats, Python binding

GNU_CONFIGURE=		yes

BUILD_DIRS=	swig/python

MAKE_FILE=	GNUmakefile

# CONFIGURE_DIR=		swig/python	# cmake
# CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_SPATIALITE=OFF
# .include "../../devel/cmake/build.mk"

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

INSTALLATION_DIRS=	bin

.include "../../mk/bsd.prefs.mk"

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

#For testing future versions from git:
#EGG_NAME=		GDAL-3.5.0.dev0
EGG_NAME?=		GDAL-${VERSION_BASE}
EGG_INFODIR?=		${EGG_NAME}-py${PYVERSSUFFIX}.egg-info
PLIST_SUBST+=		PYSITELIB=${PYSITELIB}
PLIST_SUBST+=		EGG_NAME=${EGG_NAME}-py${PYVERSSUFFIX}
PLIST_SUBST+=		EGG_INFODIR=${EGG_INFODIR}
PRINT_PLIST_AWK+=	{ gsub(/${EGG_NAME}-py${PYVERSSUFFIX}.egg-info/, \
				"$${EGG_INFODIR}") }

.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/tool.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
