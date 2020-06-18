# $NetBSD: options.mk,v 1.2 2020/06/18 12:57:48 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.hydrogen

PKG_SUPPORTED_OPTIONS+=		alsa jack portaudio pulseaudio
PKG_SUGGESTED_OPTIONS.Linux=	alsa
PKG_SUGGESTED_OPTIONS.*=	portaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CMAKE_ARGS+=	-DWANT_ALSA=ON
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWANT_ALSA=OFF
.endif

.if !empty(PKG_OPTIONS:Mjack)
CMAKE_ARGS+=	-DWANT_JACK=ON
CMAKE_ARGS+=	-DWANT_JACKSESSION=ON
.include "../../audio/jack/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWANT_JACK=OFF
CMAKE_ARGS+=	-DWANT_JACKSESSION=OFF
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
