# $NetBSD: Makefile,v 1.26 2021/12/08 16:04:46 adam Exp $
#

VERSION=	2.4.6
DISTNAME=	watchdog_pi-${VERSION}
PKGNAME=	opencpn-plugin-watchdog-${VERSION}
PKGREVISION=	5
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=rgleason/}
GITHUB_PROJECT=	watchdog_pi
GITHUB_TAG=	v${VERSION}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://opencpn.org/OpenCPN/plugins/watchdog.html
COMMENT=	Various configurable alarms in OpenCPN
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++11
USE_CMAKE=		yes

CMAKE_ARGS+=	-DPREFIX:PATH=${PREFIX} -DPREFIX_PLUGINS:PATH=${PREFIX}/lib/opencpn
CMAKE_MODULE_PATH_OVERRIDE= \
		cmake/PluginConfigure.cmake \
		cmake/PluginInstall.cmake \
		cmake/PluginLocalization.cmake \
		cmake/PluginPackage.cmake

.include "../../devel/cmake/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
