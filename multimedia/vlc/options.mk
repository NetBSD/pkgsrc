# $NetBSD: options.mk,v 1.3 2008/02/22 15:37:28 sborrill Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vlc
PKG_SUPPORTED_OPTIONS=		skins wxwidgets faad flac
PKG_SUGGESTED_OPTIONS=		wxwidgets faad flac

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
.include "../../audio/faad2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-faad
.endif

.if !empty(PKG_OPTIONS:Mflac)
CONFIGURE_ARGS+=	--enable-flac
.include "../../audio/flac/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-flac
.endif
