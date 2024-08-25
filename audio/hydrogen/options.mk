# $NetBSD: options.mk,v 1.4 2024/08/25 06:18:23 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.hydrogen

PKG_SUPPORTED_OPTIONS+=		alsa jack portaudio pulseaudio
PKG_SUGGESTED_OPTIONS.Linux=	alsa
PKG_SUGGESTED_OPTIONS.*=	portaudio

.include "../../audio/jack/platform.mk"
.if ${PLATFORM_SUPPORTS_JACK:tl} == "yes"
PKG_SUPPORTED_OPTIONS+=		jack
PKG_SUGGESTED_OPTIONS+=		jack
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CMAKE_CONFIGURE_ARGS+=	-DWANT_ALSA=ON
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_ALSA=OFF
.endif

.if !empty(PKG_OPTIONS:Mjack)
CMAKE_CONFIGURE_ARGS+=	-DWANT_JACK=ON
CMAKE_CONFIGURE_ARGS+=	-DWANT_JACKSESSION=ON
.include "../../audio/jack/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_JACK=OFF
CMAKE_CONFIGURE_ARGS+=	-DWANT_JACKSESSION=OFF
.endif

.if !empty(PKG_OPTIONS:Mportaudio)
CMAKE_CONFIGURE_ARGS+=	-DWANT_PORTAUDIO=ON
.include "../../audio/portaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_PORTAUDIO=OFF
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_CONFIGURE_ARGS+=	-DWANT_PULSEAUDIO=ON
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_PULSEAUDIO=OFF
.endif
