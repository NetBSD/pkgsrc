# $NetBSD: Makefile,v 1.16.2.1 2018/08/18 10:31:58 bsiegert Exp $
#

VERSION=	1.5_20180405
DISTNAME=	ocpn_draw_pi-${VERSION}
PKGNAME=	opencpn-plugin-draw-${VERSION}
PKGREVISION=	3
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=jongough/}
GITHUB_PROJECT=	ocpn_draw_pi
GITHUB_TAG=	e7d675a889ee5d0c2745d5716669cf82775c1eac

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://opencpn.org/OpenCPN/plugins/draw.html
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
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
