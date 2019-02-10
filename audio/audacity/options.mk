# $NetBSD: options.mk,v 1.3 2019/02/10 17:14:42 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.audacity
PKG_SUPPORTED_OPTIONS=		debug jack ladspa nls
PKG_SUGGESTED_OPTIONS+=		ladspa nls
PLIST_VARS+=			nls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=		--enable-debug=yes
.else
CONFIGURE_ARGS+=		--enable-debug=no
.endif

.if !empty(PKG_OPTIONS:Mjack)
.include "../../audio/jack/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mladspa)
.include "../../audio/ladspa/buildlink3.mk"
CONFIGURE_ARGS+=		--enable-ladspa=yes
.else
CONFIGURE_ARGS+=		--enable-ladspa=no
.endif

.if !empty(PKG_OPTIONS:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
PLIST.nls=			yes
.else
CONFIGURE_ARGS+=		--disable-nls
.endif
