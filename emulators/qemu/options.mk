# $NetBSD: options.mk,v 1.3 2017/02/27 05:19:29 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qemu
PKG_SUPPORTED_OPTIONS=	gtk3 ivshmem sdl

.include "../../mk/bsd.fast.prefs.mk"

.if empty(MACHINE_PLATFORM:MNetBSD-[5-6].*-*)
PKG_SUGGESTED_OPTIONS+=	ivshmem
.endif

.if empty(OPSYS:MDarwin)
PKG_SUGGESTED_OPTIONS+=	sdl
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk ivshmem

.if !empty(PKG_OPTIONS:Mivshmem)
PLIST.ivshmem=		yes
.endif

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
