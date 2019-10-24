# $NetBSD: options.mk,v 1.4 2019/10/24 16:36:56 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.lmms

PKG_SUPPORTED_OPTIONS+=		alsa jack portaudio pulseaudio sdl
PKG_SUGGESTED_OPTIONS.Linux+=	alsa

.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/oss.buildlink3.mk"

# XXX may want to use SDL2 on NetBSD when support is released

.if ${OPSYS} != "Linux" && ${OSS_TYPE} == "none"
PKG_SUGGESTED_OPTIONS+=		portaudio
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CMAKE_ARGS+=	-DWANT_ALSA=ON
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWANT_ALSA=OFF
.endif

.if !empty(PKG_OPTIONS:Mjack)
CMAKE_ARGS+=	-DWANT_JACK=ON
.include "../../audio/jack/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWANT_JACK=OFF
.endif

.if !empty(PKG_OPTIONS:Mportaudio)
CMAKE_ARGS+=	-DWANT_PORTAUDIO=ON
.include "../../audio/portaudio/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWANT_PORTAUDIO=OFF
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_ARGS+=	-DWANT_PULSEAUDIO=ON
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWANT_PULSEAUDIO=OFF
.endif

.if !empty(PKG_OPTIONS:Msdl)
CMAKE_ARGS+=	-DWANT_SDL=ON
# libSDL defines some symbols that are also defined in libX11, which has
# been fixed in SDL 1.2.11.
BUILDLINK_ABI_DEPENDS.SDL+=	SDL>=1.2.11
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../audio/SDL_sound/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWANT_SDL=OFF
.endif
