# $NetBSD: Makefile,v 1.4 2016/06/16 15:57:02 bouyer Exp $
#

VERSION=	1.1p13
#PKGREVISION=	2
DISTNAME=	ocpn_draw_pi-${VERSION}
PKGNAME=	opencpn-plugin-draw-${VERSION}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=jongough/}
GITHUB_PROJECT=	ocpn_draw_pi
GITHUB_TAG=	6f831259b474295559a0823f53d8f57a0dc35fdc

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
