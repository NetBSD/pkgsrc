# $NetBSD: Makefile,v 1.33 2024/10/04 03:49:19 ryoon Exp $

DISTNAME=	fifengine-0.4.2
PKGREVISION=	28
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=fifengine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.fifengine.net/
COMMENT=	Multi-platform isometric game engine
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	swig3>=3.0:../../devel/swig3

.include "../../lang/python/extension.mk"

.if ${PYTHON_VERSION} > 311
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
.endif

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CXX_FEATURES+=	c++11

UNLIMIT_RESOURCES=	datasize virtualsize

PY_PATCHPLIST=	yes

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"

.include "../../devel/cmake/build.mk"
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
