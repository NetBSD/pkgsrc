# $NetBSD: options.mk,v 1.23 2024/02/20 19:08:39 imil Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qemu
PKG_SUPPORTED_OPTIONS=	debug debug-info gtk3 iscsi jack sdl spice
PKG_SUGGESTED_OPTIONS+=	iscsi sdl spice

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Linux"
PKG_SUPPORTED_OPTIONS+=	virtfs-proxy-helper
.endif

.if ${OPSYS} != "Darwin"
# NetBSD<9.0 does not have EGL support in native X11,
# so the QEMU OpenGL display driver cannot build.
.  include "../../graphics/MesaLib/features.mk"
.  if !empty(MESALIB_SUPPORTS_EGL:M[Yy][Ee][Ss])
PKG_SUPPORTED_OPTIONS+=	opengl
PKG_SUGGESTED_OPTIONS+=	opengl
.  endif
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk keymap virtfs-proxy-helper

.if !empty(PKG_OPTIONS:Mjack)
CONFIGURE_ARGS+=	--enable-jack
.include "../../audio/jack/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-jack
.endif

.if !empty(PKG_OPTIONS:Mdebug-info)
CONFIGURE_ARGS+=	--enable-debug-info
.else
CONFIGURE_ARGS+=	--disable-debug-info
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Mgtk3)
PLIST.gtk=		yes
CONFIGURE_ARGS+=	--enable-gtk
.include "../../x11/gtk3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

.if !empty(PKG_OPTIONS:Mopengl)
CONFIGURE_ARGS+=	--enable-opengl
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-opengl
.endif

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--enable-sdl
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-sdl
.endif

# On Darwin, qemu uses Cocoa
.if ${OPSYS} != "Darwin"
.  if !empty(PKG_OPTIONS:Mgtk3) || \
    !empty(PKG_OPTIONS:Mopengl) || !empty(PKG_OPTIONS:Msdl)
PLIST.keymap=		yes
.include "../../x11/libxkbcommon/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-xkbcommon
.  endif
.endif

# NB to successfully build virtfs-proxy-helper, the upstream Linux
# header/development libraries for libcap and libattr must be installed.
.if ${OPSYS} == "Linux" && !empty(PKG_OPTIONS:Mvirtfs-proxy-helper)
PLIST.virtfs-proxy-helper=	yes
CONFIGURE_ARGS+=		--enable-virtfs
.elif ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=		--enable-virtfs
.else
CONFIGURE_ARGS+=		--disable-virtfs
.endif

.if !empty(PKG_OPTIONS:Mspice)
CONFIGURE_ARGS+=	--enable-spice
.include "../../sysutils/spice-protocol/buildlink3.mk"
.include "../../sysutils/spice-server/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-spice
.endif

.if !empty(PKG_OPTIONS:Miscsi)
CONFIGURE_ARGS+=	--enable-libiscsi
.include "../../net/libiscsi/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libiscsi
.endif
