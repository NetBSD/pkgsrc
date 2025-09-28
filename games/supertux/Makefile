# $NetBSD: Makefile,v 1.65 2025/09/28 15:58:14 adam Exp $

PKGNAME=	supertux-0.6.3
PKGREVISION=	18
DISTNAME=	SuperTux-v${PKGVERSION_NOREV}-Source
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=SuperTux/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	hernani@vecirex.net
HOMEPAGE=	https://www.supertux.org/
COMMENT=	2D jump and run game in the style of the Super Mario ones
LICENSE=	gnu-gpl-v2

USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

CMAKE_CONFIGURE_ARGS+=	-DINSTALL_SUBDIR_BIN=bin
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=OFF
CMAKE_CONFIGURE_ARGS+=	-DBoost_INCLUDE_DIR=${BUILDLINK_DIR}/include/boost

# We already patch 'configure'...
CHECK_PORTABILITY_SKIP+=	external/SDL_ttf/configure.in

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.endif

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glm/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
