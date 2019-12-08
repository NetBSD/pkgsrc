# $NetBSD: options.mk,v 1.2 2019/12/08 02:01:07 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.csound6
PKG_SUPPORTED_OPTIONS=	jack portaudio pulseaudio

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Linux"
PKG_SUPPORTED_OPTIONS+=	alsa
PKG_SUGGESTED_OPTIONS+=	alsa
.elif ${OPSYS} != "Darwin" && ${OPSYS} != "Haiku"
PKG_SUGGESTED_OPTIONS+=	portaudio
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		alsa
.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
CMAKE_ARGS+=		-DUSE_ALSA=ON
PLIST.alsa=		yes
.else
CMAKE_ARGS+=		-DUSE_ALSA=OFF
.endif

PLIST_VARS+=		jack
.if !empty(PKG_OPTIONS:Mjack)
.include "../../audio/jack/buildlink3.mk"
CMAKE_ARGS+=		-DUSE_JACK=ON
PLIST.jack=		yes
.else
CMAKE_ARGS+=		-DUSE_JACK=OFF
.endif

PLIST_VARS+=		portaudio
.if !empty(PKG_OPTIONS:Mportaudio)
.include "../../audio/portaudio/buildlink3.mk"
CMAKE_ARGS+=		-DUSE_PORTAUDIO=ON
CMAKE_ARGS+=		-DPORTAUDIO_INCLUDE_PATH=${BUILDLINK_DIR}/include/portaudio2
CMAKE_ARGS+=		-DCMAKE_LIBRARY_PATH=${BUILDLINK_PREFIX.portaudio}/lib/portaudio2
PLIST.portaudio=	yes
.else
CMAKE_ARGS+=		-DUSE_PORTAUDIO=OFF
.endif

PLIST_VARS+=            pulseaudio
.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
CMAKE_ARGS+=		-DUSE_PULSEAUDIO=ON
PLIST.pulseaudio=	yes
.else
CMAKE_ARGS+=		-DUSE_PULSEAUDIO=OFF
.endif
