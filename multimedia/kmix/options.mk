# $NetBSD: options.mk,v 1.1 2013/04/03 11:13:10 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kmix
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
