# $NetBSD: options.mk,v 1.9 2019/07/05 15:21:18 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.audacious-plugins
PKG_SUPPORTED_OPTIONS=	jack pulseaudio sid
PKG_SUGGESTED_OPTIONS+=	pulseaudio jack

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	sid
.if !empty(PKG_OPTIONS:Msid)
.  include "../../audio/libsidplay/buildlink3.mk"
PLIST.sid=	yes
.else
CONFIGURE_ARGS+=	--disable-sid
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
