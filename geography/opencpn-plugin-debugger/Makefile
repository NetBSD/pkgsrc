# $NetBSD: Makefile,v 1.10.2.1 2018/08/18 10:31:58 bsiegert Exp $
#

VERSION=	20170414
PKGREVISION=	6
DISTNAME=	ocpndebugger_pi-${VERSION}
PKGNAME=	opencpn-plugin-debugger-${VERSION}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=nohal/}
GITHUB_PROJECT=	ocpndebugger_pi
GITHUB_TAG=	f2cea39ffcbf61c84e2d6066b155d866eaebff0f

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://opencpn.org/OpenCPN/plugins/debugger.html
COMMENT=	Shows the messages on OpenCPN's plugin interface
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
