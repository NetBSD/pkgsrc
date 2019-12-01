# $NetBSD: options.mk,v 1.3 2019/12/01 12:51:57 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.fluidsynth
PKG_SUPPORTED_OPTIONS=		alsa jack portaudio pulseaudio sdl2
PKG_SUGGESTED_OPTIONS.Linux=	alsa

.include "../../mk/oss.buildlink3.mk"

.if ${OPSYS} != "Linux" && ${OSS_TYPE} == "none"
PKG_SUGGESTED_OPTIONS+=		sdl2
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CMAKE_ARGS+=	-Denable-alsa=ON
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_ARGS+=	-Denable-alsa=OFF
.endif

.if !empty(PKG_OPTIONS:Mjack)
CMAKE_ARGS+=	-Denable-jack=ON
.include "../../audio/jack/buildlink3.mk"
.else
CMAKE_ARGS+=	-Denable-jack=OFF
.endif

.if !empty(PKG_OPTIONS:Mportaudio)
CMAKE_ARGS+=	-Denable-portaudio=ON
.include "../../audio/portaudio/buildlink3.mk"
.else
CMAKE_ARGS+=	-Denable-portaudio=OFF
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_ARGS+=	-Denable-pulseaudio=ON
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_ARGS+=	-Denable-pulseaudio=OFF
.endif

.if !empty(PKG_OPTIONS:Msdl2)
CMAKE_ARGS+=	-Denable-sdl2=ON
.include "../../devel/SDL2/buildlink3.mk"
.else
CMAKE_ARGS+=	-Denable-sdl2=OFF
.endif
