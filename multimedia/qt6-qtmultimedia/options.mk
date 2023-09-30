# $NetBSD: options.mk,v 1.4 2023/09/30 08:04:40 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.qt6-qtmultimedia
PKG_SUPPORTED_OPTIONS=		gstreamer pulseaudio

.include "../../mk/bsd.fast.prefs.mk"

PLIST_VARS+=			ffmpeg gstreamer pulseaudio

.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS+=		gstreamer pulseaudio
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgstreamer)
CONFIGURE_ARGS+=	-gstreamer
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gst-plugins1-bad/buildlink3.mk"
PLIST.gstreamer=	yes
.else
CONFIGURE_ARGS+=	-no-gstreamer
.endif

# the pulseaudio option must come after the gstreamer option
.if !empty(PKG_OPTIONS:Mpulseaudio)
CONFIGURE_ARGS+=	-pulseaudio
PLIST.pulseaudio=	yes
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	-no-pulseaudio
.endif

# For some reason ffmpeg support is conditional on pulseaudio OR apple
# in src/multimedia/configure.cmake
.if !empty(PKG_OPTIONS:Mpulseaudio) || ${OPSYS} == "Darwin"
.include "../../multimedia/ffmpeg6/buildlink3.mk"
PLIST.ffmpeg=		yes
.endif
