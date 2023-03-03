# $NetBSD: options.mk,v 1.2 2023/03/03 09:54:56 tnn Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.qt6-qtmultimedia
PKG_SUPPORTED_OPTIONS=		gstreamer pulseaudio

.include "../../mk/bsd.fast.prefs.mk"

PLIST_VARS+=			gstreamer ffmpeg

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
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	-no-pulseaudio
.endif

# For some reason ffmpeg support is conditional on pulseaudio OR apple
# in src/multimedia/configure.cmake
.if !empty(PKG_OPTIONS:Mpulseaudio) || ${OPSYS} == "Darwin"
.include "../../multimedia/ffmpeg5/buildlink3.mk"
PLIST.ffmpeg=		yes
.endif
