# $NetBSD: Makefile,v 1.20 2018/11/12 03:52:08 ryoon Exp $
#

VERSION=	20180827
DISTNAME=	weather_routing_pi-${VERSION}
PKGNAME=	opencpn-plugin-weather_routing-${VERSION}
PKGREVISION=	1
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=seandepagnier/}
GITHUB_PROJECT=	weather_routing_pi
GITHUB_TAG=	44695011d39c390784220589b9bd25932b73af3e

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://opencpn.org/OpenCPN/plugins/weatherroute.html
COMMENT=	creates optimized weather routes using grib data in OpenCPN
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++
USE_TOOLS=		gettext
USE_CMAKE=		yes

CMAKE_ARGS+=	-DPREFIX:PATH=${PREFIX} -DPREFIX_PLUGINS:PATH=${PREFIX}/lib/opencpn
CMAKE_MODULE_PATH_OVERRIDE = \
		cmake/PluginConfigure.cmake \
		cmake/PluginInstall.cmake \
		cmake/PluginLocalization.cmake \
		cmake/PluginPackage.cmake

SUBST_CLASSES+=	isnan
SUBST_STAGE.isnan=	pre-configure
SUBST_MESSAGE.isnan=	replace wxIsNaN with std::isnan
SUBST_FILES.isnan=	src/BoatDialog.cpp \
			src/ReportDialog.cpp \
			src/EditPolarDialog.cpp \
			src/Polar.cpp \
			src/RouteMap.cpp \
			src/RouteMapOverlay.cpp \
			src/SailboatTransform.cpp \
			src/WeatherRouting.cpp
SUBST_SED.isnan=	-e s,wxIsNaN,std::isnan,g


.include "../../devel/cmake/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
