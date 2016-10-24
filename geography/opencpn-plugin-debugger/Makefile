# $NetBSD: Makefile,v 1.1 2016/10/24 17:58:29 bouyer Exp $
#

VERSION=	20160224
#PKGREVISION=	2
DISTNAME=	ocpndebugger_pi-${VERSION}
PKGNAME=	opencpn-plugin-debugger-${VERSION}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=nohal/}
GITHUB_PROJECT=	ocpndebugger_pi
GITHUB_TAG=	cabe866ac37933150cd410604c6e61fbf2278816

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://github.com/nohal/ocpndebugger_pi
COMMENT=	Shows the messages on the plugin interface
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
