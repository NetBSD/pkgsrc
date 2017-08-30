# $NetBSD: options.mk,v 1.4 2017/08/30 21:00:46 kamil Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qemu
PKG_SUPPORTED_OPTIONS=	gtk3 sdl

.include "../../mk/bsd.fast.prefs.mk"

.if empty(OPSYS:MDarwin)
PKG_SUGGESTED_OPTIONS+=	sdl
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk

.if !empty(PKG_OPTIONS:Mgtk3)
PLIST.gtk=		yes
CONFIGURE_ARGS+=	--enable-gtk
.include "../../x11/gtk3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--enable-sdl
.include "../../devel/SDL2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-sdl
.endif
