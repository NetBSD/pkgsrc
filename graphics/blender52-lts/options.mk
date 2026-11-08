# $NetBSD: options.mk,v 1.1 2026/11/08 16:15:18 ryoon Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.blender52
PKG_SUPPORTED_OPTIONS=		jack pulseaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjack)
CMAKE_CONFIGURE_ARGS+=	-DWITH_JACK=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_JACK_DYNLOAD=OFF
.include "../../audio/jack/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_JACK=OFF
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_CONFIGURE_ARGS+=	-DWITH_PULSEAUDIO=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_PULSEAUDIO_DYNLOAD=OFF
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_PULSEAUDIO=OFF
.endif
