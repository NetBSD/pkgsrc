# $NetBSD: options.mk,v 1.1 2015/04/20 13:38:23 rodent Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.audacity
PKG_SUPPORTED_OPTIONS=		alsa debug jack ladspa nls
PKG_SUGGESTED_OPTIONS+=		gtk2 ladspa nls
PKG_OPTIONS_OPTIONAL_GROUPS+=	gui
PKG_OPTIONS_GROUP.gui=		gtk2 gtk3
PLIST_VARS+=			nls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
BROKEN=				error: 'ESTRPIPE' undeclared
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=		--enable-debug=yes
.else
CONFIGURE_ARGS+=		--enable-debug=no
.endif

.if !empty(PKG_OPTIONS:Mgtk2)
.include "../../x11/gtk2/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mgtk3)
.include "../../x11/gtk3/buildlink3.mk"
CONFIGURE_ARGS+=		--enable-gtk3
BROKEN=				gtk3 option needs work
.endif

.if !empty(PKG_OPTIONS:Mjack)
.include "../../audio/jack/buildlink3.mk"
BROKEN=				Fails to build with jack support
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
