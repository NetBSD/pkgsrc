# $NetBSD: Makefile,v 1.1 2016/04/24 10:21:54 bouyer Exp $
#

VERSION=	20160415
DISTNAME=	ocpn_draw_pi-${VERSION}
PKGNAME=	opencpn-plugin-draw-${VERSION}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=jongough/}
GITHUB_PROJECT=	ocpn_draw_pi
GITHUB_TAG=	047bb4c19c45e75f0bef3aba17ef7b52ef43d8af

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://opencpn.org/ocpn/Plugins_external_odraw
COMMENT=	place georeferenced objects/items on the OpenCPN interface
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
