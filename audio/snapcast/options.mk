# $NetBSD: options.mk,v 1.2 2024/08/25 06:18:25 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.snapcast
PKG_SUPPORTED_OPTIONS=		alsa avahi pulseaudio
PKG_SUGGESTED_OPTIONS.Linux+=	alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CMAKE_CONFIGURE_ARGS+=		-DBUILD_WITH_ALSA=ON
.  include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=		-DBUILD_WITH_ALSA=OFF
.endif

.if !empty(PKG_OPTIONS:Mavahi)
CMAKE_CONFIGURE_ARGS+=		-DBUILD_WITH_AVAHI=ON
.  include "../../net/avahi/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=		-DBUILD_WITH_AVAHI=OFF
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_CONFIGURE_ARGS+=		-DBUILD_WITH_PULSE=ON
.  include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=		-DBUILD_WITH_PULSE=OFF
.endif
