# $NetBSD: options.mk,v 1.5 2011/12/06 22:01:06 sborrill Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vlc
PKG_SUPPORTED_OPTIONS=		skins wxwidgets faad arts esound sdl x11 x264
PKG_SUGGESTED_OPTIONS=		wxwidgets faad x11 sdl x264

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

.if !empty(PKG_OPTIONS:Mx264)
CONFIGURE_ARGS+=	--enable-x264
PLIST.x264=		yes
.include "../../multimedia/x264-devel/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-x264
.endif

.if !empty(PKG_OPTIONS:Mesound)
CONFIGURE_ARGS+=	--enable-esd
PLIST.esound=		yes
.include "../../audio/esound/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-esd
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

