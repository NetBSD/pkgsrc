# $NetBSD: options.mk,v 1.7 2022/04/01 11:53:28 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.mumble
PKG_SUPPORTED_OPTIONS=		alsa dbus jack pulseaudio portaudio
PKG_SUGGESTED_OPTIONS=		dbus portaudio
PKG_SUGGESTED_OPTIONS.Linux=	alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CMAKE_ARGS+=	-Dalsa=on
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_ARGS+=	-Dalsa=off
.endif

.if !empty(PKG_OPTIONS:Mdbus)
CMAKE_ARGS+=	-Ddbus=on
.else
CMAKE_ARGS+=	-Ddbus=off
.endif

.if !empty(PKG_OPTIONS:Mjack)
CMAKE_ARGS+=	-Djackaudio=on
.include "../../audio/jack/buildlink3.mk"
.else
CMAKE_ARGS+=	-Djackaudio=off
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_ARGS+=	-Dpulseaudio=on
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_ARGS+=	-Dpulseaudio=off
.endif

.if !empty(PKG_OPTIONS:Mportaudio)
CMAKE_ARGS+=	-Dportaudio=on
.include "../../audio/portaudio/buildlink3.mk"
.else
CMAKE_ARGS+=	-Dportaudio=off
.endif
