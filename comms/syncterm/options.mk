# $NetBSD: options.mk,v 1.2 2025/03/06 04:33:36 vins Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.syncterm
PKG_OPTIONS_NONEMPTY_SETS=	display sound
PKG_OPTIONS_SET.display=	curses sdl2 x11
PKG_OPTIONS_SET.sound=		alsa oss portaudio pulseaudio sdl2

PKG_SUPPORTED_OPTIONS=	alsa curses jxl oss portaudio pulseaudio sdl2 x11
PKG_SUGGESTED_OPTIONS=	curses sdl2 x11

.if ${OPSYS:M*BSD} || ${OPSYS} == "DragonFly"
PKG_SUGGESTED_OPTIONS+=	oss
.elif ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS+=	alsa
.endif

.include "../../mk/bsd.options.mk"

##
## ALSA sound backend.
##
.if !empty(PKG_OPTIONS:Malsa)
.  include "../../audio/alsa-lib/buildlink3.mk"
.else
MAKE_FLAGS+=	WITHOUT_ALSA_SOUND=yes
.endif

##
## Enable curses interface.
## Choose the right curses library based on CURSES_TYPE.
##
.if !empty(PKG_OPTIONS:Mcurses)
.  include "../../mk/curses.buildlink3.mk"
USE_CURSES=	getmouse haldelay wide
FAKE_NCURSES=	yes
.  if !${CURSES_TYPE:M*ncurses*}
CFLAGS+=	-DUSE_SYSTEM_CURSES
.  else
CFLAGS+=	-DN_CURSES_LIB
.  endif
.endif

##
## JXL
## Support JPEG XL graphics.
##
.if !empty(PKG_OPTIONS:Mjxl)
.  include "../../graphics/libjxl/buildlink3.mk"
.else
MAKE_FLAGS+=	WITHOUT_JPEG_XL=1
.endif

##
## OSS sound backend.
## Use native OSS or ossaudio(3) library.
##
.if !empty(PKG_OPTIONS:Moss)
.  include "../../mk/oss.buildlink3.mk"
SUBST_CLASSES+=         oss
SUBST_STAGE.oss=        pre-configure
SUBST_MESSAGE.oss=      Correcting the path to the OSS device.
SUBST_FILES.oss+=	src/xpdev/xpbeep.c
SUBST_SED.oss+=         -e "s,/dev/dsp,${DEVOSSAUDIO},g"
.  if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
LDFLAGS+=               ${LIBOSSAUDIO}
.  endif
.endif

##
## PortAudio sound backend.
##
.if !empty(PKG_OPTIONS:Mportaudio)
.  include "../../audio/portaudio/buildlink3.mk"
CFLAGS+=	-DWITH_PORTAUDIO
.else
MAKE_FLAGS+=	WITHOUT_PORTAUDIO=1
.endif

##
## Pulseaudio sound backend.
##
.if !empty(PKG_OPTIONS:Mpulseaudio)
.  include "../../audio/pulseaudio/buildlink3.mk"
.else
MAKE_FLAGS+=	NO_PULSEAUDIO=1
.endif

##
## SDL2
## Enable SDL2 based display interface
##
.if !empty(PKG_OPTIONS:Msdl2)
.  include "../../devel/SDL2/buildlink3.mk"
MAKE_FLAGS+=	USE_SDL=1
MAKE_FLAGS+=	USE_SDL_AUDIO=1
MAKE_FLAGS+=	SDL_CONFIG=${PREFIX}/bin/sdl2-config
.else
MAKE_FLAGS+=	WITHOUT_SDL=1
.endif

##
## X11
## Enable X11 based display interface
##
.if !empty(PKG_OPTIONS:Mx11)
.  include "../../x11/libXinerama/buildlink3.mk"
.  include "../../x11/libXrandr/buildlink3.mk"
.  include "../../x11/libX11/buildlink3.mk"
MAKE_FLAGS+=	X_PATH=${X11BASE:Q}
.else
MAKE_FLAGS+=	NO_X=1
.endif
