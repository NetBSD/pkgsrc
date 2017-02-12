# $NetBSD: Makefile,v 1.5 2017/02/12 06:25:23 ryoon Exp $
#

VERSION=	20160716
DISTNAME=	watchdog_pi-${VERSION}
PKGNAME=	opencpn-plugin-watchdog-${VERSION}
PKGREVISION=	3
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=seandepagnier/}
GITHUB_PROJECT=	watchdog_pi
GITHUB_TAG=	a724fda3c88c48e6c3e3f7a5f9ea38c152680d74

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://opencpn.org/ocpn/Plugins_external_watchdog
COMMENT=	implements various configurable alarms in OpenCPN
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
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
