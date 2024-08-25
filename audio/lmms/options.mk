# $NetBSD: options.mk,v 1.7 2024/08/25 06:18:24 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.lmms

PKG_SUPPORTED_OPTIONS+=		alsa jack portaudio pulseaudio sdl
PKG_SUGGESTED_OPTIONS.Linux+=	alsa

.include "../../audio/jack/platform.mk"
.if ${PLATFORM_SUPPORTS_JACK:tl} == "yes"
PKG_SUPPORTED_OPTIONS+=		jack
PKG_SUGGESTED_OPTIONS+=		jack
.endif

.include "../../mk/oss.buildlink3.mk"

.if ${OPSYS} != "Linux" && ${OSS_TYPE} == "none"
PKG_SUGGESTED_OPTIONS+=		portaudio
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CMAKE_CONFIGURE_ARGS+=	-DWANT_ALSA=ON
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_ALSA=OFF
.endif

.if !empty(PKG_OPTIONS:Mjack)
CMAKE_CONFIGURE_ARGS+=	-DWANT_JACK=ON
.include "../../audio/jack/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_JACK=OFF
.endif

.if !empty(PKG_OPTIONS:Mportaudio)
CMAKE_CONFIGURE_ARGS+=	-DWANT_PORTAUDIO=ON
.include "../../audio/portaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_PORTAUDIO=OFF
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_CONFIGURE_ARGS+=	-DWANT_PULSEAUDIO=ON
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_PULSEAUDIO=OFF
.endif

.if !empty(PKG_OPTIONS:Msdl)
CMAKE_CONFIGURE_ARGS+=	-DWANT_SDL=ON
# libSDL defines some symbols that are also defined in libX11, which has
# been fixed in SDL 1.2.11.
BUILDLINK_ABI_DEPENDS.SDL+=	SDL>=1.2.11
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../audio/SDL_sound/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_SDL=OFF
.endif
