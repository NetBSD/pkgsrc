# $NetBSD: Makefile,v 1.148 2022/07/02 16:53:10 ryoon Exp $

DISTNAME=	SDL-1.2.15
PKGREVISION=	39
CATEGORIES=	devel games
MASTER_SITES=	http://www.libsdl.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libsdl.org/
COMMENT=	Simple DirectMedia Layer, a cross-platform multimedia library
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
PTHREAD_OPTS+=		require

CONFLICTS+=		sdl12-compat-[0-9]*

# Fixes skippy audio output in pygame. Also matches SDL2 where the
# non-blocking audio code was removed.
CPPFLAGS.NetBSD+=	-DUSE_BLOCKING_WRITES

CPPFLAGS+=		-DPREFIX="\"${PREFIX}\""
CPPFLAGS+=		-DX11BASE="\"${X11BASE}\""

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64") && ${OPSYS} != "SunOS"
BUILD_DEPENDS+=		yasm>=0.6.0:../../devel/yasm
NASMFLAGS_ELF=		-f elf
NASMFLAGS_a.out=	-f aoutb
.else
CONFIGURE_ARGS+=	--disable-nasm
.endif

CONFIGURE_ARGS+=	--disable-esd
CONFIGURE_ARGS+=	--disable-video-ps2gs
CONFIGURE_ARGS+=	--disable-video-ps3

CONFIGURE_ENV+=		NASMFLAGS="${NASMFLAGS_${OBJECT_FMT}}"
MAKE_ENV+=		NASMFLAGS="${NASMFLAGS_${OBJECT_FMT}}"

# See <http://developer.apple.com/qa/qa2007/qa1567.html>.
.if ${OPSYS} == "Darwin"
.  if !empty(OS_VERSION:M9.*)
LDFLAGS+=	-Wl,-dylib_file -Wl,/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGL.dylib:/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGL.dylib
.  endif
.endif

.include "../../mk/oss.buildlink3.mk"

AM_CFLAGS=		-D_PATH_DEV_DSP="\"${DEVOSSAUDIO}\""
MAKE_ENV+=		AM_CFLAGS=${AM_CFLAGS:M*:Q}

# Irix comes with GL, which works fine for SDL
.if ${OPSYS} != "IRIX" && ${OPSYS} != "Darwin"
CONFIGURE_ARGS+=	--disable-x11-shared
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif
.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "pth"
# Let SDL know that we do not have native pthreads and are using GNU pth.
CONFIGURE_ARGS+=	--disable-pthreads
CONFIGURE_ARGS+=	--enable-pth
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
