# $NetBSD: options.mk,v 1.2 2011/02/25 20:39:24 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kdemultimedia
PKG_SUPPORTED_OPTIONS=	pulseaudio alsa
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_PulseAudio:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_ALSA:BOOL=OFF
.endif
