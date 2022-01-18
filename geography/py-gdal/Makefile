# $NetBSD: Makefile,v 1.43 2022/01/18 17:42:26 gdt Exp $

PKGREVISION= 1
.include "../../geography/gdal-lib/Makefile.common"
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
#PKGREVISION=	0

COMMENT=	Translator library for raster geospatial data formats, Python binding

BUILD_DIRS=	swig/python

MAKE_FILE=	GNUmakefile

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	swig/python/scripts/*py

INSTALLATION_DIRS=	bin

.include "../../mk/bsd.prefs.mk"

EGG_NAME?=		GDAL-${VERSION_BASE}
EGG_INFODIR?=		${EGG_NAME}-py${PYVERSSUFFIX}.egg-info
PLIST_SUBST+=		PYSITELIB=${PYSITELIB}
PLIST_SUBST+=		EGG_NAME=${EGG_NAME}-py${PYVERSSUFFIX}
PLIST_SUBST+=		EGG_INFODIR=${EGG_INFODIR}
PRINT_PLIST_AWK+=	{ gsub(/${EGG_NAME}-py${PYVERSSUFFIX}.egg-info/, \
				"$${EGG_INFODIR}") }

.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
