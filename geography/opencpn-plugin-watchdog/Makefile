# $NetBSD: Makefile,v 1.16 2018/08/27 15:59:07 bouyer Exp $
#

VERSION=	20180827
DISTNAME=	watchdog_pi-${VERSION}
PKGNAME=	opencpn-plugin-watchdog-${VERSION}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=seandepagnier/}
GITHUB_PROJECT=	watchdog_pi
GITHUB_TAG=	eea8cb97a5596868f99cff15176fd35b36780e28

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://opencpn.org/OpenCPN/plugins/watchdog.html
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
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
