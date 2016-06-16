# $NetBSD: Makefile,v 1.5 2016/06/16 16:03:55 bouyer Exp $
#

VERSION=	20160611
DISTNAME=	weather_routing_pi-${VERSION}
PKGNAME=	opencpn-plugin-weather_routing-${VERSION}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=seandepagnier/}
GITHUB_PROJECT=	weather_routing_pi
GITHUB_TAG=	264605a7a9e3b33e10bbd2375a7d3fd55518b3dc

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://opencpn.org/ocpn/weather_routing_plugin
COMMENT=	Concise ChartPlotter/Navigator - developement version
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
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
