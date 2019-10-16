# $NetBSD: options.mk,v 1.1 2019/10/16 23:22:08 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.musescore
PKG_SUPPORTED_OPTIONS=		alsa jack portaudio pulseaudio

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS=		alsa
.else
PKG_SUGGESTED_OPTIONS=		portaudio
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CMAKE_ARGS+=	-DBUILD_ALSA=ON
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_ARGS+=	-DBUILD_ALSA=OFF
.endif

.if !empty(PKG_OPTIONS:Mjack)
CMAKE_ARGS+=	-DBUILD_JACK=ON
.include "../../audio/jack/buildlink3.mk"
.else
CMAKE_ARGS+=	-DBUILD_JACK=OFF
.endif

.if !empty(PKG_OPTIONS:Mportaudio)
CMAKE_ARGS+=	-DBUILD_PORTAUDIO=ON
.include "../../audio/portaudio-devel/buildlink3.mk"
.else
CMAKE_ARGS+=	-DBUILD_PORTAUDIO=OFF
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_ARGS+=	-DBUILD_PULSEAUDIO=ON
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_ARGS+=	-DBUILD_PULSEAUDIO=OFF
.endif
