# $NetBSD: options.mk,v 1.3 2020/04/02 15:52:46 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xine-lib

# Video outputs
PKG_SUPPORTED_OPTIONS+=	aalib sdl wayland x11
# Codecs
PKG_SUPPORTED_OPTIONS+=	dts

.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} == "none" && \
    ${OPSYS} != "Darwin" && \
    ${OPSYS} != "NetBSD" && \
    ${OPSYS} != "SunOS" && \
    ${OPSYS} != "Linux"
PKG_SUGGESTED_OPTIONS+=	sdl
.endif

PKG_SUGGESTED_OPTIONS+=	x11

.include "../../devel/wayland/platform.mk"

.if ${PLATFORM_SUPPORTS_WAYLAND} == "yes"
PKG_SUGGESTED_OPTIONS+=	wayland
.endif

PLIST_VARS+=	gl2

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		aalib
.if !empty(PKG_OPTIONS:Maalib)
PLIST.aalib=		yes
CONFIGURE_ARGS+=	--enable-aalib
.include "../../graphics/aalib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-aalib
.endif

# Marked NO_BIN_ON_*.  Only enable if you don't want to distribute packages.
PLIST_VARS+=		dts
.if !empty(PKG_OPTIONS:Mdts)
.include "../../audio/libdca/buildlink3.mk"
PLIST.dts=		yes
.else
CONFIGURE_ARGS+=	--disable-dts
.endif

PLIST_VARS+=		sdl
.if !empty(PKG_OPTIONS:Msdl)
PLIST.sdl=		yes
CONFIGURE_ARGS+=	--with-sdl
.include "../../devel/SDL/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-sdl
.endif

PLIST_VARS+=		wayland
.if !empty(PKG_OPTIONS:Mwayland)
PLIST.wayland=		yes
PLIST.gl2=		yes
CONFIGURE_ARGS+=	--enable-wayland
.include "../../devel/wayland/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-wayland
.endif

PLIST_VARS+=		x11
.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=		yes
PLIST.gl2=		yes
CONFIGURE_ARGS+=	--with-x
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xvmc
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-xcb
.endif
