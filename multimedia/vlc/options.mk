# $NetBSD: options.mk,v 1.1 2007/10/31 15:35:30 sborrill Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vlc
PKG_SUPPORTED_OPTIONS=		skins wxwidgets
PKG_SUGGESTED_OPTIONS=		wxwidgets

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mskins)
CONFIGURE_ARGS+=	--enable-skins
PLIST_SUBST+=		COND_SKINS=
.else
CONFIGURE_ARGS+=	--disable-skins
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
