# $NetBSD: Makefile,v 1.1 2026/04/18 15:08:09 js Exp $

DISTNAME=	SDL3_mixer-3.2.0
CATEGORIES=	audio devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libsdl-org/}
GITHUB_PROJECT=	SDL_mixer
GITHUB_RELEASE=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libsdl-org/SDL_mixer
COMMENT=	Sample multi-channel audio mixer library
LICENSE=	zlib

USE_TOOLS+=		pkg-config

# Don't dynamically load things - we build it with support for it.
CMAKE_CONFIGURE_ARGS+=	-DSDLMIXER_DEPS_SHARED=OFF
CMAKE_CONFIGURE_ARGS+=	-DSDLMIXER_VORBIS_STB=OFF
CMAKE_CONFIGURE_ARGS+=	-DSDLMIXER_EXAMPLES=OFF
CMAKE_CONFIGURE_ARGS+=	-DSDLMIXER_TESTS_INSTALL=OFF

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/game-music-emu/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxmp+=	libxmp>=4.2
.include "../../audio/libxmp/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/opusfile/buildlink3.mk"
.include "../../audio/wavpack/buildlink3.mk"
.include "../../devel/SDL3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
