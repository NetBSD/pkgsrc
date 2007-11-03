# $NetBSD: options.mk,v 1.2 2007/11/03 17:40:29 sborrill Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vlc
PKG_SUPPORTED_OPTIONS=		skins wxwidgets
PKG_SUGGESTED_OPTIONS=		wxwidgets

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
