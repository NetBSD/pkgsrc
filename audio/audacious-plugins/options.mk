# $NetBSD: options.mk,v 1.3 2008/11/10 11:08:27 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.audacious-plugins
PKG_SUPPORTED_OPTIONS=	arts esound inet6 jack midi # pulse sid

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	sid
#.if !empty(PKG_OPTIONS:Msid)
#.  include "../../wip/resid-builder/buildlink3.mk"
#PLIST.sid=	yes
#.else
#CONFIGURE_ARGS+=	--disable-sid
#.endif

PLIST_VARS+=	arts
.if !empty(PKG_OPTIONS:Marts)
.  include "../../audio/arts/buildlink3.mk"
PLIST.arts=	yes
.else
CONFIGURE_ARGS+=	--disable-arts
.endif

PLIST_VARS+=	esd
.if !empty(PKG_OPTIONS:Mesound)
.  include "../../audio/esound/buildlink3.mk"
PLIST.esd=	yes
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

PLIST_VARS+=	jack
.if !empty(PKG_OPTIONS:Mjack)
.  include "../../audio/jack/buildlink3.mk"
PLIST.jack=	yes
.else
CONFIGURE_ARGS+=	--disable-jack
.endif

PLIST_VARS+=	midi
.if !empty(PKG_OPTIONS:Mmidi)
BUILD_DEPENDS+=		timidity>=0:../../audio/timidity
PLIST.midi=	yes
.else
CONFIGURE_ARGS+=	--disable-timidity
.endif

PLIST_VARS+=	pulse
#.if !empty(PKG_OPTIONS:Mpulse)
#.  include "../../wip/pulseaudio/buildlink3.mk"
#PLIST.pulse=	yes
#.else
#CONFIGURE_ARGS+=	--disable-pulse
#.endif
