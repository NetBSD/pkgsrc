# $NetBSD: Makefile,v 1.34 2022/08/11 05:08:35 gutteridge Exp $

PKGNAME=		supertux-0.6.2
PKGREVISION=		10
DISTNAME=		SuperTux-v${PKGVERSION_NOREV}-Source
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GITHUB:=SuperTux/}
GITHUB_RELEASE=		v${PKGVERSION_NOREV}

MAINTAINER=		hernani@vecirex.net
HOMEPAGE=		https://www.supertux.org/
COMMENT=		2D jump and run game in the style of the Super Mario ones
LICENSE=		gnu-gpl-v2

USE_CMAKE=		yes
CMAKE_ARGS+=		-DINSTALL_SUBDIR_BIN=bin
CMAKE_ARGS+=		-DBUILD_SHARED_LIBS=off
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++14

# C++14
GCC_REQD+=		5

# We already patch 'configure'...
CHECK_PORTABILITY_SKIP+=	external/SDL_ttf/configure.in

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
