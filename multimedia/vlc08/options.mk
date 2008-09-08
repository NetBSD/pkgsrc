# $NetBSD: options.mk,v 1.1 2008/09/08 18:42:21 ahoka Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vlc
PKG_SUPPORTED_OPTIONS=		skins wxwidgets faad arts
PKG_SUGGESTED_OPTIONS=		wxwidgets faad

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mskins)
CONFIGURE_ARGS+=	--enable-skins2
PLIST.skins=		yes
.else
CONFIGURE_ARGS+=	--disable-skins2
.endif

.if !empty(PKG_OPTIONS:Mwxwidgets)
.include "../../x11/wxGTK/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-wxwidgets
PLIST.wxwidgets=	yes
.else
CONFIGURE_ARGS+=	--disable-wxwidgets
.endif

.if !empty(PKG_OPTIONS:Mfaad)
CONFIGURE_ARGS+=	--enable-faad
PLIST.faad=		yes
.include "../../audio/faad2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-faad
.endif

.if !empty(PKG_OPTIONS:Marts)
CONFIGURE_ARGS+=	--enable-arts
PLIST.arts=		yes
.include "../../audio/arts/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-arts
.endif
