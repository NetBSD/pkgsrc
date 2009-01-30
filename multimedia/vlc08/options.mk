# $NetBSD: options.mk,v 1.3 2009/01/30 13:35:26 sborrill Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vlc
PKG_SUPPORTED_OPTIONS=		skins wxwidgets faad arts sdl x11
PKG_SUGGESTED_OPTIONS=		wxwidgets faad x11 sdl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mskins) && !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--enable-skins2
PLIST.skins=		yes
.else
CONFIGURE_ARGS+=	--disable-skins2
.endif

.if !empty(PKG_OPTIONS:Mwxwidgets) && !empty(PKG_OPTIONS:Mx11)
.include "../../x11/wxGTK26/buildlink3.mk"
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

## SDL backend support

.if !empty(PKG_OPTIONS:Msdl)
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
PLIST.sdl=		yes
.else
CONFIGURE_ARGS+=	--disable-sdl
CONFIGURE_ARGS+=	--disable-sdl-image
.endif

.if !empty(PKG_OPTIONS:Mx11)
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-x11
CONFIGURE_ARGS+=	--enable-freetype
PLIST.x11=		yes
.else
CONFIGURE_ARGS+=	--disable-x11
CONFIGURE_ARGS+=	--disable-freetype
.endif

