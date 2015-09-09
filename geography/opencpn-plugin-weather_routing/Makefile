# $NetBSD: Makefile,v 1.3 2015/09/09 11:07:07 bouyer Exp $
#

VERSION=	20150829
DISTNAME=	weather_routing_pi-${VERSION}
PKGNAME=	opencpn-plugin-weather_routing-${VERSION}
#PKGREVISION=	1
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=seandepagnier/}
GITHUB_PROJECT=	weather_routing_pi
GITHUB_TAG=	e652536aca24809cd3514c8c903603806b22bb0d

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://opencpn.org/ocpn/weather_routing_plugin
COMMENT=	OpenCPN plugin to create optimized weather routes
LICENSE=	gnu-gpl-v2

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
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
