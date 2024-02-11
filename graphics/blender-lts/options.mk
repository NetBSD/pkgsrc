# $NetBSD: options.mk,v 1.3 2024/02/11 15:29:58 ryoon Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.blender
PKG_SUPPORTED_OPTIONS=		jack pulseaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjack)
CMAKE_ARGS+=	-DWITH_JACK=ON
CMAKE_ARGS+=	-DWITH_JACK_DYNLOAD=OFF
.include "../../audio/jack/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_JACK=OFF
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_ARGS+=	-DWITH_PULSEAUDIO=ON
CMAKE_ARGS+=	-DWITH_PULSEAUDIO_DYNLOAD=OFF
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWITH_PULSEAUDIO=OFF
.endif
