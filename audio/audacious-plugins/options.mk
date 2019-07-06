# $NetBSD: options.mk,v 1.10 2019/07/06 13:17:01 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.audacious-plugins
PKG_SUPPORTED_OPTIONS+=		alsa jack pulseaudio lirc
PKG_SUPPORTED_OPTIONS+=		adplug sidplay fluidsynth libgme modplug
PKG_SUGGESTED_OPTIONS.Linux+=	alsa lirc
PKG_OPTIONS_LEGACY_OPTS+=	sid:sidplay

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	alsa
.if !empty(PKG_OPTIONS:Malsa)
.  include "../../audio/alsa-lib/buildlink3.mk"
PLIST.alsa=	yes
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

PLIST_VARS+=	jack
.if !empty(PKG_OPTIONS:Mjack)
.  include "../../audio/jack/buildlink3.mk"
PLIST.jack=	yes
.else
CONFIGURE_ARGS+=	--disable-jack
.endif

PLIST_VARS+=	pulse
.if !empty(PKG_OPTIONS:Mpulseaudio)
.  include "../../audio/pulseaudio/buildlink3.mk"
PLIST.pulse=	yes
.else
CONFIGURE_ARGS+=	--disable-pulse
.endif

PLIST_VARS+=	lirc
.if !empty(PKG_OPTIONS:Mlirc)
.  include "../../comms/lirc/buildlink3.mk"
PLIST.lirc=	yes
.else
CONFIGURE_ARGS+=	--disable-lirc
.endif

PLIST_VARS+=	adplug
.if !empty(PKG_OPTIONS:Madplug)
.  include "../../audio/adplug/buildlink3.mk"
PLIST.adplug=	yes
.else
CONFIGURE_ARGS+=	--disable-adplug
.endif

PLIST_VARS+=	sid
.if !empty(PKG_OPTIONS:Msidplay)
.  include "../../audio/libsidplay/buildlink3.mk"
PLIST.sid=	yes
.else
CONFIGURE_ARGS+=	--disable-sid
.endif

PLIST_VARS+=	fluidsynth
.if !empty(PKG_OPTIONS:Mfluidsynth)
.  include "../../audio/fluidsynth/buildlink3.mk"
PLIST.fluidsynth=	yes
.else
CONFIGURE_ARGS+=	--disable-amidiplug
.endif

PLIST_VARS+=	libgme
.if !empty(PKG_OPTIONS:Mlibgme)
.  include "../../audio/game-music-emu/buildlink3.mk"
PLIST.libgme=	yes
.else
CONFIGURE_ARGS+=	--disable-console
.endif

PLIST_VARS+=	modplug
.if !empty(PKG_OPTIONS:Mmodplug)
.  include "../../audio/libmodplug/buildlink3.mk"
PLIST.modplug=	yes
.else
CONFIGURE_ARGS+=	--disable-modplug
.endif
