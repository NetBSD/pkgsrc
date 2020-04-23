# $NetBSD: options.mk,v 1.8 2020/04/23 15:52:02 nia Exp $
#
PKG_OPTIONS_VAR=	PKG_OPTIONS.freerdp
PKG_SUPPORTED_OPTIONS=	alsa cups ffmpeg pcsc pulseaudio debug
PKG_SUGGESTED_OPTIONS=	alsa cups ffmpeg

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	alsa ffmpeg pcsc pulseaudio

# Package-specific option-handling

###
### ALSA support
###
.if !empty(PKG_OPTIONS:Malsa)
.  include "../../audio/alsa-lib/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_ALSA=ON
PLIST.alsa=	yes
.else
CMAKE_ARGS+=	-DWITH_ALSA=OFF
.endif

###
### CUPS support
###
.if !empty(PKG_OPTIONS:Mcups)
.  include "../../print/cups-base/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_CUPS=ON
PLIST.cups=	yes
.else
CMAKE_ARGS+=	-DWITH_CUPS=OFF
.endif

###
### FFmpeg support
###
.if !empty(PKG_OPTIONS:Mffmpeg)
.  include "../../multimedia/ffmpeg4/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_FFMPEG=ON
PLIST.ffmpeg=	yes
.else
CMAKE_ARGS+=	-DWITH_FFMPEG=OFF
.endif

###
### PC/SC support
###
.if !empty(PKG_OPTIONS:Mpcsc)
.  include "../../security/pcsc-lite/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_PCSC=ON
PLIST.pcsc=	yes
.else
CMAKE_ARGS+=	-DWITH_PCSC=OFF
.endif

###
### PulseAudio support
###
.if !empty(PKG_OPTIONS:Mpulseaudio)
.  include "../../audio/pulseaudio/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_PULSEAUDIO=ON
PLIST.pulseaudio=	yes
.else
CMAKE_ARGS+=	-DWITH_PULSEAUDIO=OFF
.endif

###
### Debug support
###
.if !empty(PKG_OPTIONS:Mdebug)
#CMAKE_ARGS+=	-DWITH_DEBUG_TRANSPORT=ON
CMAKE_ARGS+=	-DWITH_DEBUG_CHANNELS=ON
CMAKE_ARGS+=	-DWITH_DEBUG_SVC=ON
CMAKE_ARGS+=	-DWITH_DEBUG_DVC=ON
CMAKE_ARGS+=	-DWITH_DEBUG_NEGO=ON
CMAKE_ARGS+=	-DWITH_DEBUG_REDIR=ON
CMAKE_ARGS+=	-DWITH_DEBUG_GDI=ON
.endif
