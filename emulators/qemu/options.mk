# $NetBSD: options.mk,v 1.10 2020/05/28 14:44:19 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qemu
PKG_SUPPORTED_OPTIONS=	gtk3 iscsi sdl spice
PKG_SUGGESTED_OPTIONS+=	iscsi

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Linux"
PKG_SUPPORTED_OPTIONS+=	virtfs-proxy-helper
.endif

.if ${OPSYS} != "Darwin"
PKG_SUPPORTED_OPTIONS+=	opengl
PKG_SUGGESTED_OPTIONS+=	opengl sdl
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
