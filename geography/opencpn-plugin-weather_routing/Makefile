# $NetBSD: Makefile,v 1.1 2015/02/02 20:41:34 bouyer Exp $
#

VERSION=	20150201
DISTNAME=	weather_routing_pi-${VERSION}
PKGNAME=	opencpn-plugin-weather_routing-${VERSION}
CATEGORIES=	geography
MASTER_SITES=	http://ftp.fr.netbsd.org/~bouyer/

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
.include "../../mk/bsd.pkg.mk"
