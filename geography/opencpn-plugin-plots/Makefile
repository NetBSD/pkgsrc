# $NetBSD: Makefile,v 1.13 2024/10/20 14:03:52 wiz Exp $
#

VERSION=	2.2.12
PKGREVISION=	11
DISTNAME=	ocpn_plots_pi-${VERSION}
PKGNAME=	opencpn-plugin-plots-${VERSION}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=rgleason/}
GITHUB_PROJECT=	plots_pi
GITHUB_TAG=	v${VERSION}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://opencpn.org/OpenCPN/plugins/sweepplot.html
COMMENT=	visualizes sailing performance data
LICENSE=	gnu-gpl-v3

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
