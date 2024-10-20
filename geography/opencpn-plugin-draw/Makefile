# $NetBSD: Makefile,v 1.37 2024/10/20 14:03:52 wiz Exp $
#

VERSION=	1.6.8
DISTNAME=	ocpn_draw_pi-${VERSION}
PKGNAME=	opencpn-plugin-draw-${VERSION}
PKGREVISION=	13
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=jongough/}
GITHUB_PROJECT=	ocpn_draw_pi
GITHUB_TAG=	v${VERSION}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://opencpn.org/OpenCPN/plugins/draw.html
COMMENT=	place georeferenced objects/items on the OpenCPN interface
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++11
USE_CMAKE=		yes

CMAKE_CONFIGURE_ARGS+=	-DPREFIX:PATH=${PREFIX} -DPREFIX_PLUGINS:PATH=${PREFIX}/lib/opencpn
CMAKE_MODULE_PATH_OVERRIDE = \
		cmake/PluginConfigure.cmake \
		cmake/PluginInstall.cmake \
		cmake/PluginLocalization.cmake \
		cmake/PluginPackage.cmake

.include "../../devel/cmake/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
