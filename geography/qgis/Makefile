# $NetBSD: Makefile,v 1.269 2026/04/29 16:19:38 gdt Exp $

# This is intentionally 3.44, about to be Long Term Release.  Please
# do not update to later branches without MAINTAINER consensus.  The
# transition to 4.0/4.2 and qt6 will be particularly tricky.
DISTNAME=	qgis-3.44.9
CATEGORIES=	geography
MASTER_SITES=	https://qgis.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gdt@NetBSD.org
#MAINTAINER+=	brook@nmsu.edu
#MAINTAINER+=	bouyer@NetBSD.org
HOMEPAGE=	https://www.qgis.org/
#STATUSPAGE=	https://qgis.org/resources/roadmap/
COMMENT=	Geographic Information System (GIS)
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++ fortran77
USE_CXX_FEATURES=	c++17
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
# 3.40.7 fails with BSD make. \todo File upstream.
# \todo Only set this if CMAKE_GENERATOR=make.
USE_TOOLS+=		gmake
USE_TOOLS+=		bison flex perl pkg-config
.include "../../devel/cmake/build.mk"

# minizip/zip.h shadows zip.h (from libzip)
BUILDLINK_TRANSFORM+=	rm:-I${PREFIX}/include/minizip

DEPENDS+=		qca2-qt5-ossl-[0-9]*:../../security/qca2-qt5-ossl
TOOL_DEPENDS+=		${PYPKGPREFIX}-sip6-[0-9]*:../../x11/py-sip6
TOOL_DEPENDS+=		${PYPKGPREFIX}-qt-builder-[0-9]*:../../x11/py-qt-builder
DEPENDS+=		${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5
DEPENDS+=		${PYPKGPREFIX}-qt5-qscintilla-[0-9]*:../../x11/py-qt5-qscintilla

# This is needed to find qca2.
CMAKE_PREFIX_PATH+=	${QTDIR}

# This could be used if we want to build pdf doc, which is currently false
#TOOL_DEPENDS+=	txt2tags-[0-9]*:../../wip/txt2tags

# Disable building of QGIS.app.  \todo Consider building it.
SUBST_CLASSES+=		xapple
SUBST_STAGE.xapple=	pre-configure
SUBST_MESSAGE.xapple=	Disabling APPLE App in cmake scripts
xapple_FIND_CMD=	cd ${WRKSRC} && \
			find . -name '*.cmake' -o -name CMakeLists.txt
SUBST_FILES.xapple=	${xapple_FIND_CMD:sh}
SUBST_SED.xapple+=	-e 's,APPLE,XAPPLE,'
SUBST_SED.xapple+=	-e 's,MACOSX_BUNDLE ,,'
SUBST_NOOP_OK.xapple=	yes # since SUBST_FILES is generated

SUBST_CLASSES+=		pyqt
SUBST_STAGE.pyqt=	pre-configure
SUBST_MESSAGE.pyqt=	Use correct python version for PyQt5 programs
SUBST_FILES.pyqt=	cmake/FindPyQt5.cmake
SUBST_SED.pyqt+=	-e '/^ *SET/s,pyuic5,&-${PYVERSSUFFIX},'
SUBST_SED.pyqt+=	-e '/^ *SET/s,pyrcc5,&-${PYVERSSUFFIX},'
SUBST_SED.pyqt+=	-e '/ *FIND_PROGRAM(__pyuic5 /s,"pyuic5,&-${PYVERSSUFFIX},'

# Optimize for understandability when the build output is examined,
# because it is only examined when there are failures.
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_VERBOSE_MAKEFILE=TRUE

# qgis looks for ccache and uses it, which does not play well with wrappers.
# Plus, there's something buggy about ccache, precompiled headers, and gcc.
CMAKE_CONFIGURE_ARGS+=		-DUSE_CCACHE:BOOL=FALSE

# Precompiled headers are buggy in the presence of ASLR.
#   https://gcc.gnu.org/bugzilla/show_bug.cgi?id=71934
#   https://gnats.netbsd.org/cgi-bin/query-pr-single.pl?number=59746
CMAKE_CONFIGURE_ARGS+=		-DUSE_PRECOMPILED_HEADERS:BOOL=FALSE

CMAKE_CONFIGURE_ARGS+=		-DWITH_BINDINGS:BOOL=TRUE

CMAKE_CONFIGURE_ARGS+=		-DWITH_INTERNAL_MARKUPSAFE=FALSE
CMAKE_CONFIGURE_ARGS+=		-DWITH_INTERNAL_NLOHMANN_JSON=OFF

# We patch cmake to look only in QWT_DIR, so provide it.
CMAKE_CONFIGURE_ARGS+=		-DQWT_DIR=${QWT_DIR}

# qgis defaults to building webkit and fails if not found.
CMAKE_CONFIGURE_ARGS+=		-DWITH_QTWEBKIT=FALSE

# \todo Add Qt53DCoreConfig.cmake
CMAKE_CONFIGURE_ARGS+=		-DWITH_3D=FALSE

# Server support is WIP; it has merely been tested that regular use
# has not been broken.
CMAKE_CONFIGURE_ARGS+=		-DWITH_SERVER:BOOL=TRUE
# \todo Upstream installs in the wrong place by default.
CMAKE_CONFIGURE_ARGS+=		-DQGIS_CGIBIN_SUBDIR=libexec/cgi-bin

# \todo Consider (optional?) dependency on GRASS.
# \todo Consider (optional?) dependency on SAGA.

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-psycopg2-[0-9]*:../../databases/py-psycopg2
DEPENDS+=	${PYPKGPREFIX}-gdal-[0-9]*:../../geography/py-gdal
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markupsafe-[0-9]*:../../textproc/py-markupsafe
# for quickosm
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
# for metasearch
DEPENDS+=	${PYPKGPREFIX}-owslib-[0-9]*:../../geography/py-owslib

.include "../../lang/python/pyversion.mk"
PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../mk/pgsql.buildlink3.mk"

# ? qt-webengine
# ? laz-perf

.include "../../archivers/libzip/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../geography/draco/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../geography/libspatialite/buildlink3.mk"
.include "../../geography/pdal-lib/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../geography/spatialindex/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
.include "../../security/qca2-qt5/buildlink3.mk"
.include "../../security/qt5-qtkeychain/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"
.include "../../www/fcgi/buildlink3.mk"
.include "../../x11/qt5-qscintilla/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../x11/qt5-qtserialport/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qwt6-qt5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
