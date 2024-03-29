# $NetBSD: Makefile,v 1.28 2024/01/30 14:21:39 ryoon Exp $

DISTNAME=	fifengine-0.4.2
PKGREVISION=	25
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=fifengine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.fifengine.net/
COMMENT=	Multi-platform isometric game engine
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++11

UNLIMIT_RESOURCES=	datasize virtualsize

TOOL_DEPENDS+=	swig3>=3.0:../../devel/swig3

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

PY_PATCHPLIST=	yes

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/fifechan/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
