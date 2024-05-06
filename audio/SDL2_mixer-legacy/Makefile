# $NetBSD: Makefile,v 1.1 2024/05/06 18:01:31 nia Exp $

DISTNAME=	SDL2_mixer-2.0.1
CATEGORIES=	audio devel
MASTER_SITES=	https://www.libsdl.org/projects/SDL_mixer/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libsdl.org/projects/SDL_mixer/
COMMENT=	Sample multi-channel audio mixer library
LICENSE=	zlib

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	SDL2_mixer.pc.in

CONFIGURE_ARGS.Darwin+=	--disable-music-midi-native

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/opusfile/buildlink3.mk"
.include "../../multimedia/smpeg2/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
