# $NetBSD: Makefile,v 1.26 2025/01/19 18:13:51 wiz Exp $

DISTNAME=	SDL2_mixer-2.8.0
CATEGORIES=	audio devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libsdl-org/}
GITHUB_PROJECT=	SDL_mixer
GITHUB_RELEASE=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libsdl-org/SDL_mixer
COMMENT=	Sample multi-channel audio mixer library
LICENSE=	zlib

# needs sort -V
TOOL_DEPENDS+=	coreutils-[0-9]*:../../sysutils/coreutils

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	SDL2_mixer.pc.in

CONFIGURE_ARGS+=	--disable-music-ogg-stb --enable-music-ogg-vorbis
CONFIGURE_ARGS+=	--disable-music-flac-drflac --enable-music-flac-libflac
CONFIGURE_ARGS+=	--disable-music-mp3-drmp3 --enable-music-mp3-mpg123
# needs sort -V
CONFIGURE_ARGS+=	SORT=${PREFIX}/gnu/bin/sort

.include "options.mk"

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/game-music-emu/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxmp+=	libxmp>=4.2
.include "../../audio/libxmp/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/opusfile/buildlink3.mk"
.include "../../audio/wavpack/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
