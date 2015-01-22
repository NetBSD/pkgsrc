# $NetBSD: Makefile,v 1.3 2015/01/22 12:34:15 bouyer Exp $
#

VERSION=	4.0.0
DISTNAME=	OpenCPN-${VERSION}-Source
PKGNAME=	opencpn-${VERSION}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opencpn/${VERSION}/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.opencpn.org/
COMMENT=	Concise ChartPlotter/Navigator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS=		gettext
USE_CMAKE=		yes

CMAKE_ARGS+=	-DPREFIX:PATH=${PREFIX} -DPREFIX_PLUGINS:PATH=${PREFIX}/lib/opencpn
CMAKE_ARGS+=	-DBUNDLE_DOCS=ON -DBUNDLE_GSHHS=CRUDE -DBUNDLE_TCDATA=ON
CMAKE_MODULE_PATH_OVERRIDE = \
		plugins/grib_pi/CMakeLists.txt \
		plugins/demo_pi_sample/src/CMakeLists.txt \
		plugins/demo_pi_sample/CMakeLists.txt \
		plugins/dashboard_pi/CMakeLists.txt \
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
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/portaudio-devel/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
