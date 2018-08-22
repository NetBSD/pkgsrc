# $NetBSD: Makefile,v 1.68 2018/08/22 09:45:10 wiz Exp $

DISTNAME=	qgis-2.18.16
PKGREVISION=	7
CATEGORIES=	geography
MASTER_SITES=	https://qgis.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://www.qgis.org/
COMMENT=	Geographic Information System (GIS)
LICENSE=	gnu-gpl-v2

USE_CMAKE=		yes
USE_LANGUAGES=		c c++ fortran77
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		cmake bison flex perl
# Due to gmake specific quoting of $ and spaces in filenames, we must use gmake
USE_TOOLS+=		gmake

PLIST_SRC=		PLIST

CMAKE_ARGS+=	-DENABLE_QT5=OFF

.include "options.mk"

DEPENDS+=     qca2-ossl-[0-9]*:../../security/qca2-ossl
DEPENDS+=     qt4-sqlite3-[0-9]*:../../x11/qt4-sqlite3
# This is needed to find qca2.
CMAKE_PREFIX_PATH+=${QTDIR}

# This could be used if we want to build pdf doc, which is currently false
#BUILD_DEPENDS+= txt2tags-[0-9]*:../../wip/txt2tags

# Disable building of QGIS.app
# (XXX For now, we might want to find a way to do this later.)
SUBST_CLASSES+=			xapple
SUBST_STAGE.xapple=		pre-configure
SUBST_MESSAGE.xapple=		Disabling APPLE App in cmake scripts
xapple_FIND_CMD= 		cd ${WRKSRC} && \
	find . -name '*.cmake' -o -name CMakeLists.txt
SUBST_FILES.xapple=		${xapple_FIND_CMD:sh}
SUBST_SED.xapple+=		-e 's,APPLE,XAPPLE,'
SUBST_SED.xapple+=		-e 's,MACOSX_BUNDLE ,,'

CMAKE_ARGS+= 	-DWITH_QTWEBKIT=FALSE
# Useful for package development:
#CMAKE_ARGS+= 	-DCMAKE_VERBOSE_MAKEFILE=TRUE

CONFIGURE_DIRS=build
CMAKE_ARG_PATH=..

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/fcgi/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../geography/libspatialite/buildlink3.mk"
.include "../../geography/spatialindex/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qwt-qt4/buildlink3.mk"
.include "../../x11/qt4-qscintilla/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
