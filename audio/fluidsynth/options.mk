# $NetBSD: options.mk,v 1.2 2019/10/20 11:10:47 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.fluidsynth
PKG_SUPPORTED_OPTIONS=		alsa jack portaudio pulseaudio
PKG_SUGGESTED_OPTIONS.Linux=	alsa

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
