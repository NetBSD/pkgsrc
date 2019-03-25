# $NetBSD: Makefile,v 1.21 2019/03/25 11:44:52 bouyer Exp $
#

VERSION=	1.5_20190311
DISTNAME=	ocpn_draw_pi-${VERSION}
PKGNAME=	opencpn-plugin-draw-${VERSION}
#PKGREVISION=	2
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=jongough/}
GITHUB_PROJECT=	ocpn_draw_pi
GITHUB_TAG=	6b400ef572948cfe1ee6e511a982e50aad4a6427

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://opencpn.org/OpenCPN/plugins/draw.html
COMMENT=	place georeferenced objects/items on the OpenCPN interface
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++11
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
