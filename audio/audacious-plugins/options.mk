# $NetBSD: options.mk,v 1.1.1.1 2008/10/20 09:32:19 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.audacious-plugins
PKG_SUPPORTED_OPTIONS=	arts esound inet6 jack midi # pulse sid

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msid)
.  include "../../wip/resid-builder/buildlink3.mk"
PLIST_SUBST+=		SID=""
.else
CONFIGURE_ARGS+=	--disable-sid
PLIST_SUBST+=		SID="@comment "
.endif

.if !empty(PKG_OPTIONS:Marts)
.  include "../../audio/arts/buildlink3.mk"
PLIST_SUBST+=		ARTS=""
.else
CONFIGURE_ARGS+=	--disable-arts
PLIST_SUBST+=		ARTS="@comment "
.endif

.if !empty(PKG_OPTIONS:Mesound)
.  include "../../audio/esound/buildlink3.mk"
PLIST_SUBST+=		ESD=""
.else
CONFIGURE_ARGS+=	--disable-esd
PLIST_SUBST+=		ESD="@comment "
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mjack)
.  include "../../audio/jack/buildlink3.mk"
PLIST_SUBST+=		JACK=""
.else
CONFIGURE_ARGS+=	--disable-jack
PLIST_SUBST+=		JACK="@comment "
.endif

.if !empty(PKG_OPTIONS:Mmidi)
BUILD_DEPENDS+=		timidity>=0:../../audio/timidity
PLIST_SUBST+=		MIDI=""
.else
CONFIGURE_ARGS+=	--disable-timidity
PLIST_SUBST+=		MIDI="@comment "
.endif

.if !empty(PKG_OPTIONS:Mpulse)
.  include "../../wip/pulseaudio/buildlink3.mk"
PLIST_SUBST+=		PULSE=""
.else
CONFIGURE_ARGS+=	--disable-pulse
PLIST_SUBST+=		PULSE="@comment "
.endif
