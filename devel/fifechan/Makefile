# $NetBSD: Makefile,v 1.15 2025/10/23 20:36:18 wiz Exp $

DISTNAME=	fifechan-0.1.5
PKGREVISION=	12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=fifengine/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fifengine.github.io/fifechan/
COMMENT=	C++ GUI library designed for games
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
