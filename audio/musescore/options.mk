# $NetBSD: options.mk,v 1.4 2024/08/25 06:18:24 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.musescore
PKG_SUPPORTED_OPTIONS=		alsa jack portaudio pulseaudio

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS=		alsa
.else
PKG_SUGGESTED_OPTIONS=		portaudio
.endif

.include "../../audio/jack/platform.mk"
.if ${PLATFORM_SUPPORTS_JACK:tl} == "yes"
PKG_SUPPORTED_OPTIONS+=		jack
PKG_SUGGESTED_OPTIONS+=		jack
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CMAKE_CONFIGURE_ARGS+=	-DBUILD_ALSA=ON
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DBUILD_ALSA=OFF
.endif

.if !empty(PKG_OPTIONS:Mjack)
CMAKE_CONFIGURE_ARGS+=	-DBUILD_JACK=ON
.include "../../audio/jack/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DBUILD_JACK=OFF
.endif

.if !empty(PKG_OPTIONS:Mportaudio)
CMAKE_CONFIGURE_ARGS+=	-DBUILD_PORTAUDIO=ON
.include "../../audio/portaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DBUILD_PORTAUDIO=OFF
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_CONFIGURE_ARGS+=	-DBUILD_PULSEAUDIO=ON
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DBUILD_PULSEAUDIO=OFF
.endif
