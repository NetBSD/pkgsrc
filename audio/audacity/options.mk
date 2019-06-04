# $NetBSD: options.mk,v 1.4 2019/06/04 23:09:51 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.audacity
PKG_SUPPORTED_OPTIONS=		debug jack ladspa mad nls
PKG_SUGGESTED_OPTIONS+=		ladspa nls
PLIST_VARS+=			nls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=		--enable-debug=yes
.else
CONFIGURE_ARGS+=		--enable-debug=no
.endif

# for internal portaudio...
.if !empty(PKG_OPTIONS:Mjack)
CONFIGURE_ARGS+=		--with-jack
.include "../../audio/jack/buildlink3.mk"
.else
CONFIGURE_ARGS+=		--without-jack
.endif

# libmad is disabled by default because it's been unmaintained
# since 2004 and is a pile of CVEs.
.if !empty(PKG_OPTIONS:Mmad)
CONFIGURE_ARGS+=		--with-libmad
.include "../../audio/libmad/buildlink3.mk"
.else
CONFIGURE_ARGS+=		--with-libmad=no
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
