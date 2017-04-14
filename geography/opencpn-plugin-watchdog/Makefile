# $NetBSD: Makefile,v 1.6 2017/04/14 16:32:01 bouyer Exp $
#

VERSION=	20170414
DISTNAME=	watchdog_pi-${VERSION}
PKGNAME=	opencpn-plugin-watchdog-${VERSION}
#PKGREVISION=	3
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=seandepagnier/}
GITHUB_PROJECT=	watchdog_pi
GITHUB_TAG=	d804ee6ca83727c780150373077f2ffb517b7858

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://opencpn.org/ocpn/Plugins_external_watchdog
COMMENT=	implements various configurable alarms in OpenCPN
LICENSE=	gnu-gpl-v3

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
