# $NetBSD: Makefile,v 1.70 2026/03/31 10:47:12 adam Exp $

PKGNAME=	supertux-0.7.0
DISTNAME=	SuperTux-v${PKGVERSION_NOREV}-Source
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=SuperTux/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	hernani@vecirex.net
HOMEPAGE=	https://www.supertux.org/
COMMENT=	2D jump and run game in the style of the Super Mario ones
LICENSE=	gnu-gpl-v2

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

CMAKE_CONFIGURE_ARGS+=	-DDISABLE_CPACK_BUNDLING=ON
CMAKE_CONFIGURE_ARGS+=	-DINSTALL_SUBDIR_BIN=bin
CMAKE_CONFIGURE_ARGS+=	-DSSQ_BUILD_INSTALL=OFF
CMAKE_CONFIGURE_ARGS+=	-DUSE_STATIC_SIMPLESQUIRREL=ON
CMAKE_CONFIGURE_ARGS+=	-DUSE_SYSTEM_SDL2_TTF=ON

# We already patch 'configure'...
CHECK_PORTABILITY_SKIP+=	external/SDL_ttf/configure.in
CHECK_PORTABILITY_SKIP+=	mk/flatpak/gen_flatpaks.sh

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
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
BUILDLINK_API_DEPENDS.glm+=	glm>=1.0.3nb1
.include "../../graphics/glm/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
