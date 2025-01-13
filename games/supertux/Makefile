# $NetBSD: Makefile,v 1.59 2025/01/13 23:21:41 wiz Exp $

PKGNAME=		supertux-0.6.3
PKGREVISION=		14
DISTNAME=		SuperTux-v${PKGVERSION_NOREV}-Source
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GITHUB:=SuperTux/}
GITHUB_RELEASE=		v${PKGVERSION_NOREV}

MAINTAINER=		hernani@vecirex.net
HOMEPAGE=		https://www.supertux.org/
COMMENT=		2D jump and run game in the style of the Super Mario ones
LICENSE=		gnu-gpl-v2

CMAKE_CONFIGURE_ARGS+=	-DINSTALL_SUBDIR_BIN=bin
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=off
CMAKE_CONFIGURE_ARGS+=	-DBoost_INCLUDE_DIR=${BUILDLINK_DIR}/include/boost
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++14

USE_CXX_FEATURES+=	c++14

# We already patch 'configure'...
CHECK_PORTABILITY_SKIP+=	external/SDL_ttf/configure.in

.include "../../devel/cmake/build.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glm/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
