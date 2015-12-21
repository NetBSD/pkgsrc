# $NetBSD: options.mk,v 1.2 2015/12/21 12:10:22 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qemu
PKG_SUPPORTED_OPTIONS=	sdl ivshmem

.include "../../mk/bsd.fast.prefs.mk"

.if empty(MACHINE_PLATFORM:MNetBSD-[5-6].*-*)
PKG_SUGGESTED_OPTIONS+=	ivshmem
.endif

.if empty(OPSYS:MDarwin)
PKG_SUGGESTED_OPTIONS+=	sdl
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--enable-sdl
.include "../../devel/SDL/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-sdl
.endif

.if !empty(PKG_OPTIONS:Mivshmem)
PLIST.ivshmem=		yes
.endif

