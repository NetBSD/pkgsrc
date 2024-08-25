# $NetBSD: options.mk,v 1.4 2024/08/25 06:18:49 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.blender
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
