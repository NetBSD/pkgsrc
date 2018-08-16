# $NetBSD: Makefile,v 1.25 2018/08/16 18:54:50 adam Exp $

DISTNAME=	OpenCPN-4.8.2
PKGREVISION=	6
PKGNAME=	${DISTNAME:S/OpenCPN/opencpn/}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenCPN/}
GITHUB_PROJECT=	OpenCPN
GITHUB_TAG=	v4.8.2
EXTRACT_SUFX=	.zip

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.opencpn.org/
COMMENT=	Concise ChartPlotter/Navigator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	gettext pkg-config
USE_CMAKE=	yes

CMAKE_ARGS+=	-DPREFIX:PATH=${PREFIX} -DPREFIX_PLUGINS:PATH=${PREFIX}/lib/opencpn
CMAKE_ARGS+=	-DBUNDLE_DOCS=ON -DBUNDLE_GSHHS=CRUDE -DBUNDLE_TCDATA=ON
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_MODULE_PATH_OVERRIDE = \
	plugins/chartdldr_pi/CMakeLists.txt \
	plugins/dashboard_pi/CMakeLists.txt \
	plugins/grib_pi/CMakeLists.txt \
	plugins/wmm_pi/CMakeLists.txt \
	plugins/CMakeLists.txt

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	replace /usr/local with ${PREFIX}
SUBST_FILES.prefix=	src/mygdal/cpl_csv.cpp			\
			src/mygdal/cpl_findfile.cpp		\
			data/doc/help_en_US.html		\
			Findgps.cmake
SUBST_SED.prefix=	-e s,"/usr/local,"${PREFIX},g

# Ensure we export symbols in the linked shared object.
LDFLAGS+=	${EXPORT_SYMBOLS_LDFLAGS}

.include "../../devel/cmake/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/portaudio-devel/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
