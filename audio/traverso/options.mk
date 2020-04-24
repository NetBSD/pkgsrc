# $NetBSD: options.mk,v 1.1 2020/04/24 08:43:08 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.traverso
PKG_SUPPORTED_OPTIONS=	alsa jack portaudio pulseaudio

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS=	alsa jack portaudio
.else
PKG_SUGGESTED_OPTIONS=	jack portaudio
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
