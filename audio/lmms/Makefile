# $NetBSD: Makefile,v 1.33 2014/02/12 23:17:34 tron Exp $
#

DISTNAME=		lmms-0.4.15
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lmms/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://lmms.sourceforge.net/
COMMENT=		Linux MultiMedia Studio
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake perl pkg-config
USE_CMAKE=		yes

BUILDLINK_TRANSFORM+=	rm:-floop-optimize2 rm:-fgcse-las rm:-ldl

# for libzynaddsubfx.so in plugins/zynaddsubfx/.
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/lmms

# libSDL defines some symbols that are also defined in libX11, which has
# been fixed in SDL 1.2.11.
BUILDLINK_ABI_DEPENDS.SDL+=	SDL>=1.2.11

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../audio/SDL_sound/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
