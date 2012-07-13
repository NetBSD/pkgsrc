# $NetBSD: options.mk,v 1.2 2012/07/13 14:22:59 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vlc
PKG_SUPPORTED_OPTIONS=		debug faad hal skins sdl pulseaudio x11
PKG_SUPPORTED_OPTIONS+=		gnome dts rtsp
# XXX broken
#PKG_SUPPORTED_OPTIONS+=	dbus
PKG_SUGGESTED_OPTIONS=		x11 rtsp

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

## PulseAudio support

.if !empty(PKG_OPTIONS:Mpulseaudio)
CONFIGURE_ARGS+=	--enable-pulse
.include "../../audio/pulseaudio/buildlink3.mk"
PLIST.pulseaudio=	yes
.else
CONFIGURE_ARGS+=	--disable-pulse
.endif

## SDL backend support

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--enable-sdl
CONFIGURE_ARGS+=	--enable-sdl-image
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
PLIST.sdl=		yes
.else
CONFIGURE_ARGS+=	--disable-sdl
CONFIGURE_ARGS+=	--disable-sdl-image
.endif

## gnome integration

.if !empty(PKG_OPTIONS:Mgnome)
CONFIGURE_ARGS+=	--enable-gnomevfs
.include "../../sysutils/gnome-vfs/buildlink3.mk"
PLIST.gnome=	yes
.else
CONFIGURE_ARGS+=	--disable-gnomevfs
.endif

## DBUS message bus support
## also libnotify because it uses dbus
## so taking them apart would make no sense.

.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=	--enable-dbus
.include "../../sysutils/dbus/buildlink3.mk"
PLIST.dbus=		yes
CONFIGURE_ARGS+=	--enable-notify
.include "../../sysutils/libnotify/buildlink3.mk"

# telepathy needs dbus, but its also gnome-ish
.if !empty(PKG_OPTIONS:Mgnome)
.include "../../chat/libtelepathy/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-telepathy
.else
CONFIGURE_ARGS+=	--disable-telepathy
.endif

PLIST.dbus=		yes

## HAL support (requires dbus)
.if !empty(PKG_OPTIONS:Mhal)
CONFIGURE_ARGS+=	--enable-hal
.include "../../sysutils/hal/buildlink3.mk"
PLIST.hal=		yes
.else
CONFIGURE_ARGS+=	--disable-hal
.endif
.else
CONFIGURE_ARGS+=	--disable-dbus
CONFIGURE_ARGS+=	--disable-hal
CONFIGURE_ARGS+=	--disable-notify
.endif

## DEBUG build or release build

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
CONFIGURE_ARGS+=	--disable-optimizations
.else
CONFIGURE_ARGS+=	--enable-release
.endif

## SKINS frontend

.if !empty(PKG_OPTIONS:Mskins)
CONFIGURE_ARGS+=	--enable-skins2
PLIST.skins=		yes
INSTALLATION_DIRS+=	share/vlc/skins2
.else
CONFIGURE_ARGS+=	--disable-skins2
.endif

## X11 dependency and QT4 frontend

.if !empty(PKG_OPTIONS:Mx11)
DEPENDS+= dejavu-ttf>=2.0:../../fonts/dejavu-ttf
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util036/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-qt4 \
			--with-x \
			--enable-glx \
			--enable-snapshot
PLIST.x11=		yes
.else
CONFIGURE_ARGS+=	--without-x \
			--disable-xcb \
			--disable-qt4 \
			--disable-glx \
			--disable-freetype \
			--disable-snapshot
.endif

## FAAD support (faad is non-redistributable)

.if !empty(PKG_OPTIONS:Mfaad)
CONFIGURE_ARGS+=	--enable-faad
PLIST.faad=		yes
.include "../../audio/faad2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-faad
.endif

## DTS support (libdca is non-redistributable)

.if !empty(PKG_OPTIONS:Mdts)
CONFIGURE_ARGS+=	--enable-dca
PLIST.dts=		yes
.  include "../../audio/libdca/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-dca=no
.endif

## RTSP support

.if !empty(PKG_OPTIONS:Mrtsp)
CONFIGURE_ARGS+=	--enable-live555
PLIST.rtsp=		yes
BUILDLINK_API_DEPENDS.liblive+= liblive>=20111223
.  include "../../net/liblive/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-live555
.endif
