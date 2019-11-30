# $NetBSD: options.mk,v 1.1 2019/11/30 13:40:29 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.openal-soft
PKG_SUPPORTED_OPTIONS=		alsa jack pulseaudio
PKG_SUGGESTED_OPTIONS.Linux+=	alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CMAKE_ARGS+=	-DALSOFT_BACKEND_ALSA=ON
.  include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_ARGS+=	-DALSOFT_BACKEND_ALSA=OFF
.endif

.if !empty(PKG_OPTIONS:Mjack)
CMAKE_ARGS+=	-DALSOFT_BACKEND_JACK=ON
.  include "../../audio/jack/buildlink3.mk"
.else
CMAKE_ARGS+=	-DALSOFT_BACKEND_JACK=OFF
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_ARGS+=	-DALSOFT_BACKEND_PULSEAUDIO=ON
.  include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_ARGS+=	-DALSOFT_BACKEND_PULSEAUDIO=OFF
.endif
