# $NetBSD: Makefile,v 1.22 2023/11/14 14:01:57 wiz Exp $

VERSION=	20180405
PKGREVISION=	17
DISTNAME=	statusbar_pi-${VERSION}
PKGNAME=	opencpn-plugin-statusbar-${VERSION}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=seandepagnier/}
GITHUB_PROJECT=	statusbar_pi
GITHUB_TAG=	024822eb32a61f4ef4e52d4cb15bd1f4b86b2763

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
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
