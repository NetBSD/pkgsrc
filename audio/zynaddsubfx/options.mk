# $NetBSD: options.mk,v 1.1 2020/10/30 15:47:01 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.zynaddsubfx
PKG_SUPPORTED_OPTIONS=		alsa jack portaudio
PKG_SUGGESTED_OPTIONS.Linux=	alsa jack

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} == "none" && ${OPSYS} != "Linux"
PKG_SUGGESTED_OPTIONS=		portaudio
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	alsa
.if !empty(PKG_OPTIONS:Malsa)
PLIST.alsa=	yes
CMAKE_ARGS+=	-DAlsaEnable=ON
.  include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_ARGS+=	-DAlsaEnable=OFF
.endif

PLIST_VARS+=	jack
.if !empty(PKG_OPTIONS:Mjack)
PLIST.jack=	yes
CMAKE_ARGS+=	-DJackEnable=ON
.  include "../../audio/jack/buildlink3.mk"
.else
CMAKE_ARGS+=	-DJackEnable=OFF
.endif

.if !empty(PKG_OPTIONS:Mportaudio)
CMAKE_ARGS+=	-DPaEnable=ON
.  include "../../audio/portaudio/buildlink3.mk"
.else
CMAKE_ARGS+=	-DJackEnable=OFF
.endif
