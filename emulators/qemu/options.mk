# $NetBSD: options.mk,v 1.5.14.1 2020/01/27 10:59:04 bsiegert Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qemu
PKG_SUPPORTED_OPTIONS=	gtk3 sdl

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Linux"
PKG_SUPPORTED_OPTIONS+=	virtfs-proxy-helper
.endif

.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS+=	sdl
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk virtfs-proxy-helper

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

# NB to successfully build virtfs-proxy-helper, the upstream Linux
# header/development libraries for libcap and libattr must be installed.
.if !empty(PKG_OPTIONS:Mvirtfs-proxy-helper)
PLIST.virtfs-proxy-helper=	yes
CONFIGURE_ARGS+=		--enable-virtfs
.else
CONFIGURE_ARGS+=		--disable-virtfs
.endif
