# $NetBSD: options.mk,v 1.4 2020/01/05 22:20:40 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.MesaDemos
PKG_SUPPORTED_OPTIONS=		libdrm wayland x11
PKG_SUGGESTED_OPTIONS=		libdrm x11

.include "../../devel/wayland/platform.mk"
.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
PKG_SUGGESTED_OPTIONS+=		wayland
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	wayland x11

.if !empty(PKG_OPTIONS:Mlibdrm)
CONFIGURE_ARGS+=	--enable-libdrm
.include "../../x11/libdrm/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libdrm
.endif

.if !empty(PKG_OPTIONS:Mwayland)
PLIST.wayland=		yes
CONFIGURE_ARGS+=	--enable-wayland
EGL_PROGS+=		eglgears_wayland egltri_wayland
.include "../../devel/wayland/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-wayland
.endif

.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=		yes
CONFIGURE_ARGS+=	--enable-x11
EGL_PROGS+=		eglgears_x11 egltri_x11 xeglgears xeglthreads
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-x11
.endif
