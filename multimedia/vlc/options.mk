# $NetBSD: options.mk,v 1.5 2008/03/08 05:19:57 kefren Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vlc
PKG_SUPPORTED_OPTIONS=		skins wxwidgets faad arts
PKG_SUGGESTED_OPTIONS=		wxwidgets faad

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mskins)
CONFIGURE_ARGS+=	--enable-skins2
PLIST_SUBST+=		COND_SKINS=
.else
CONFIGURE_ARGS+=	--disable-skins2
PLIST_SUBST+=		COND_SKINS="@comment "
.endif

.if !empty(PKG_OPTIONS:Mwxwidgets)
.include "../../x11/wxGTK/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-wxwidgets
PLIST_SUBST+=		COND_WXWIDGETS=
.else
CONFIGURE_ARGS+=	--disable-wxwidgets
PLIST_SUBST+=		COND_WXWIDGETS="@comment "
.endif

.if !empty(PKG_OPTIONS:Mfaad)
CONFIGURE_ARGS+=	--enable-faad
PLIST_SUBST+=		COND_FAAD=
.include "../../audio/faad2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-faad
PLIST_SUBST+=		COND_FAAD="@comment "
.endif

.if !empty(PKG_OPTIONS:Marts)
CONFIGURE_ARGS+=	--enable-arts
PLIST_SUBST+=		COND_ARTS=
.include "../../audio/arts/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-arts
PLIST_SUBST+=		COND_ARTS="@comment "
.endif
