# $NetBSD: options.mk,v 1.8 2024/08/25 06:18:27 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.mumble
PKG_SUPPORTED_OPTIONS=		alsa dbus jack pulseaudio portaudio
PKG_SUGGESTED_OPTIONS=		dbus portaudio
PKG_SUGGESTED_OPTIONS.Linux=	alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CMAKE_CONFIGURE_ARGS+=	-Dalsa=on
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-Dalsa=off
.endif

.if !empty(PKG_OPTIONS:Mdbus)
CMAKE_CONFIGURE_ARGS+=	-Ddbus=on
.else
CMAKE_CONFIGURE_ARGS+=	-Ddbus=off
.endif

.if !empty(PKG_OPTIONS:Mjack)
CMAKE_CONFIGURE_ARGS+=	-Djackaudio=on
.include "../../audio/jack/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-Djackaudio=off
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_CONFIGURE_ARGS+=	-Dpulseaudio=on
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-Dpulseaudio=off
.endif

.if !empty(PKG_OPTIONS:Mportaudio)
CMAKE_CONFIGURE_ARGS+=	-Dportaudio=on
.include "../../audio/portaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-Dportaudio=off
.endif
