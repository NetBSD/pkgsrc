# $NetBSD: options.mk,v 1.7 2024/08/25 06:18:41 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.snes9x-gtk
PKG_SUPPORTED_OPTIONS=		alsa pulseaudio portaudio wayland

PKG_SUGGESTED_OPTIONS.Linux+=	alsa

.include "../../mk/oss.buildlink3.mk"

.if ${OPSYS} != "Linux" && ${OSS_TYPE} == "none"
PKG_SUGGESTED_OPTIONS+=		portaudio
.endif

.include "../../devel/wayland/platform.mk"

.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
PKG_SUGGESTED_OPTIONS+=		wayland
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DUSE_ALSA=OFF
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DUSE_PULSEAUDIO=OFF
.endif

.if !empty(PKG_OPTIONS:Mportaudio)
.include "../../audio/portaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DUSE_PORTAUDIO=OFF
.endif

.if !empty(PKG_OPTIONS:Mwayland)
.include "../../devel/wayland/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DUSE_WAYLAND=ON
.endif
