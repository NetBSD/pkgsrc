# $NetBSD: Makefile,v 1.147 2022/06/28 11:33:58 wiz Exp $

# This is intentionally 3.22 Long Term Release.  Please do not update
# to later branches, and instead discuss whether/how we want multiple
# versions.
DISTNAME=	qgis-3.22.7
PKGREVISION=	1
CATEGORIES=	geography
MASTER_SITES=	https://qgis.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gdt@NetBSD.org
#MAINTAINER+=	brook@nmsu.edu
#MAINTAINER+=	bouyer@NetBSD.orrg
HOMEPAGE=	http://www.qgis.org/
COMMENT=	Geographic Information System (GIS)
LICENSE=	gnu-gpl-v2

USE_CMAKE=		yes
USE_LANGUAGES=		c c++ fortran77
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		cmake bison flex perl pkg-config
# Due to gmake spaces in filenames, we must use gmake.  An example is
# "resources/function_help/json/Date and Time".
# Further, gmake expects files that contain a $ such as "$area" to
# appear, unsurprisingly, as "$$area" on the RHS of dependency rules.
# NetBSD make, expects "$$$$area".  While cmake 3.17 produced
# "$$area", cmake 3.18 produces "$$$$area", perhaps only on NetBSD.
USE_TOOLS+=		gmake

PLIST_SRC=		PLIST

DEPENDS+=		qca2-qt5-ossl-[0-9]*:../../security/qca2-qt5-ossl
# This is needed to find qca2.
CMAKE_PREFIX_PATH+=	${QTDIR}

# This could be used if we want to build pdf doc, which is currently false
#BUILD_DEPENDS+=	txt2tags-[0-9]*:../../wip/txt2tags

# Disable building of QGIS.app
# (XXX For now, we might want to find a way to do this later.)
SUBST_CLASSES+=			xapple
SUBST_STAGE.xapple=		pre-configure
SUBST_MESSAGE.xapple=		Disabling APPLE App in cmake scripts
xapple_FIND_CMD=		cd ${WRKSRC} && \
				find . -name '*.cmake' -o -name CMakeLists.txt
SUBST_FILES.xapple=		${xapple_FIND_CMD:sh}
SUBST_SED.xapple+=		-e 's,APPLE,XAPPLE,'
SUBST_SED.xapple+=		-e 's,MACOSX_BUNDLE ,,'
SUBST_NOOP_OK.xapple=		yes # since SUBST_FILES is generated

SUBST_CLASSES+=			pyqt
SUBST_STAGE.pyqt=		pre-configure
SUBST_MESSAGE.pyqt=		Use correct python version for PyQt5 programs
SUBST_FILES.pyqt=		cmake/PyQtMacros.cmake cmake/FindPyQt5.cmake
SUBST_SED.pyqt+=		-e '/^SET/s,pyuic5,&-${PYVERSSUFFIX},'
SUBST_SED.pyqt+=		-e '/^SET/s,pyrcc5,&-${PYVERSSUFFIX},'
SUBST_SED.pyqt+=		-e '/ *FIND_PROGRAM(__pyuic5 /s,"pyuic5,&-${PYVERSSUFFIX},'

CMAKE_ARGS+=		-DWITH_BINDINGS:BOOL=TRUE
CMAKE_ARGS+=		-DSIP_BINARY_PATH:PATH=${BUILDLINK_PREFIX.py-sip}/bin
CMAKE_ARGS+=		-DWITH_INTERNAL_MARKUPSAFE=FALSE

.include "../../lang/python/application.mk"
PYTHON_VERSIONS_INCOMPATIBLE=	27 37 # py-gdal

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-psycopg2-[0-9]*:../../databases/py-psycopg2
DEPENDS+=	${PYPKGPREFIX}-gdal-[0-9]*:../../geography/py-gdal
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markupsafe-[0-9]*:../../textproc/py-markupsafe
# for quickosm
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
# for metasearch
#DEPENDS+=	${PYPKGPREFIX}-wip-[0-9]*:../../wip/py-owslib

CMAKE_ARGS+=	-DWITH_QTWEBKIT=FALSE
CMAKE_ARGS+=	-DQWT_DIR=${QWT_DIR}
# Useful for package development:
#CMAKE_ARGS+=	-DCMAKE_VERBOSE_MAKEFILE=TRUE

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../archivers/libzip/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
##.include "../../devel/qjson/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/fcgi/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../geography/libspatialite/buildlink3.mk"
.include "../../geography/spatialindex/buildlink3.mk"
.include "../../security/qca2-qt5/buildlink3.mk"
.include "../../security/qt5-qtkeychain/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/py-qt5/buildlink3.mk"
.include "../../x11/py-qt5-qscintilla/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qwt6-qt5/buildlink3.mk"
.include "../../x11/qt5-qscintilla/buildlink3.mk"
.include "../../x11/qt5-qtserialport/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
