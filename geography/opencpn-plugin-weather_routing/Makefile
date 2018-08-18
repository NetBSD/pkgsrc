# $NetBSD: Makefile,v 1.17.2.1 2018/08/18 10:31:58 bsiegert Exp $
#

VERSION=	20180405
DISTNAME=	weather_routing_pi-${VERSION}
PKGNAME=	opencpn-plugin-weather_routing-${VERSION}
PKGREVISION=	3
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=seandepagnier/}
GITHUB_PROJECT=	weather_routing_pi
GITHUB_TAG=	c4dc8231ef0da6c7da52be22f2cded1c2880dfa4

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

.include "../../devel/cmake/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
