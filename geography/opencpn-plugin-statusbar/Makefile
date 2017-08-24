# $NetBSD: Makefile,v 1.2 2017/08/24 13:01:33 bouyer Exp $
#

VERSION=	20170414
DISTNAME=	statusbar_pi-${VERSION}
PKGNAME=	opencpn-plugin-statusbar-${VERSION}
PKGREVISION=	1
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=seandepagnier/}
GITHUB_PROJECT=	statusbar_pi
GITHUB_TAG=	b3653d44f6ecff05fbf49b49076d9a57e479268f

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://opencpn.org/OpenCPN/plugins/statusbar.html
COMMENT=	statusbar to display various info to users in OpenCPN
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
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
