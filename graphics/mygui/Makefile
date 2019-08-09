# $NetBSD: Makefile,v 1.1 2019/08/09 16:03:00 nia Exp $

DISTNAME=	mygui-3.2.3.20190707
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=MyGUI/}
GITHUB_PROJECT=	mygui
GITHUB_TAG=	0726ed4ae70b3479677a794a6a3dd5d6cc48ed62

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mygui.info/
COMMENT=	Cross-platform library for creating GUIs for games and 3D programs
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++11
USE_TOOLS+=	pkg-config

# C++11
GCC_REQD+=	4.8

CMAKE_ARGS+=	-DMYGUI_RENDERSYSTEM=7 # OpenGL 3.*
CMAKE_ARGS+=	-DMYGUI_SAMPLES_INPUT=4 # SDL2

# None of these are installed
CMAKE_ARGS+=	-DMYGUI_BUILD_DEMOS=FALSE
CMAKE_ARGS+=	-DMYGUI_BUILD_TOOLS=FALSE
CMAKE_ARGS+=	-DMYGUI_BUILD_DOCS=FALSE

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
