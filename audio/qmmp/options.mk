# $NetBSD: options.mk,v 1.3 2023/10/29 13:28:08 rhialto Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.qmmp
PKG_SUPPORTED_OPTIONS+=		alsa jack pulseaudio
PKG_SUPPORTED_OPTIONS+=		ffmpeg musepack wavpack sidplay
PKG_SUGGESTED_OPTIONS+=		ffmpeg wavpack
PKG_SUGGESTED_OPTIONS.Linux+=	alsa

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	alsa
.if !empty(PKG_OPTIONS:Malsa)
PLIST.alsa=	yes
.  include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUSE_ALSA=OFF
.endif

PLIST_VARS+=	pulse
.if !empty(PKG_OPTIONS:Mpulseaudio)
PLIST.pulse=	yes
.  include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUSE_PULSE=OFF
.endif

PLIST_VARS+=	jack
.if !empty(PKG_OPTIONS:Mjack)
PLIST.jack=	yes
.  include "../../audio/jack/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUSE_JACK=OFF
.endif

PLIST_VARS+=	ffmpeg
.if !empty(PKG_OPTIONS:Mffmpeg)
PLIST.ffmpeg=	yes
.  include "../../multimedia/ffmpeg4/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUSE_FFMPEG=OFF
.endif

PLIST_VARS+=	mpc
.if !empty(PKG_OPTIONS:Mmusepack)
PLIST.mpc=	yes
.  include "../../audio/musepack/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUSE_MPC=OFF
.endif

PLIST_VARS+=	wv
.if !empty(PKG_OPTIONS:Mwavpack)
PLIST.wv=	yes
.  include "../../audio/wavpack/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUSE_WAVPACK=OFF
.endif

PLIST_VARS+=	sid
.if !empty(PKG_OPTIONS:Msidplay)
PLIST.sid=	yes
.  include "../../audio/libsidplayfp/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUSE_SID=OFF
.endif
