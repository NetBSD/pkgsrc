# $NetBSD: options.mk,v 1.33 2019/07/02 20:52:12 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vlc
PKG_SUPPORTED_OPTIONS=		alsa avahi dbus debug dts jack pulseaudio
PKG_SUPPORTED_OPTIONS+=		vlc-skins qt5
PKG_SUGGESTED_OPTIONS=		dbus qt5
PKG_SUGGESTED_OPTIONS.Linux+=	alsa

.include "../../mk/bsd.prefs.mk"

### Add VAAPI if it is available
.include "../../multimedia/libva/available.mk"
PLIST_VARS+=		vaapi
.if ${VAAPI_AVAILABLE} == "yes"
PKG_SUPPORTED_OPTIONS+= vaapi
PKG_SUGGESTED_OPTIONS+=	vaapi
.endif

### Add LIRC if it is available
.include "../../comms/lirc/available.mk"
PLIST_VARS+=		lirc
.if ${LIRC_AVAILABLE} == "yes"
PKG_SUPPORTED_OPTIONS+= lirc
PKG_SUGGESTED_OPTIONS+=	lirc
.endif

###
.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

## ALSA support

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
PLIST.alsa=	yes
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

## Avahi support

.if !empty(PKG_OPTIONS:Mavahi)
CONFIGURE_ARGS+=	--enable-avahi
.include "../../net/avahi/buildlink3.mk"
PLIST.avahi=	yes
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

## PulseAudio support

.if !empty(PKG_OPTIONS:Mpulseaudio)
CONFIGURE_ARGS+=	--enable-pulse
.include "../../audio/pulseaudio/buildlink3.mk"
PLIST.pulseaudio=	yes
.else
CONFIGURE_ARGS+=	--disable-pulse
.endif

## Jack Audio Connection Kit support

.if !empty(PKG_OPTIONS:Mjack)
CONFIGURE_ARGS+=	--enable-jack
.include "../../audio/jack/buildlink3.mk"
PLIST.jack=		yes
.else
CONFIGURE_ARGS+=	--disable-jack
.endif

## DBUS message bus support

.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=	--enable-dbus
.include "../../sysutils/dbus/buildlink3.mk"
PLIST.dbus=		yes
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

## DEBUG build or release build

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
CONFIGURE_ARGS+=	--disable-optimizations
.endif

## SKINS frontend

.if !empty(PKG_OPTIONS:Mvlc-skins)
CONFIGURE_ARGS+=	--enable-skins2
PLIST.vlc-skins=	yes
INSTALLATION_DIRS+=	share/vlc/skins2
.else
CONFIGURE_ARGS+=	--disable-skins2
.endif

## X11 dependency and QT5 frontend

PLIST_VARS+=		egl
.if !empty(PKG_OPTIONS:Mqt5)
DEPENDS+= dejavu-ttf>=2.0:../../fonts/dejavu-ttf
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-qt \
			--with-x
PLIST.qt5=		yes
.  if ${X11_TYPE} == "modular" || exists(${X11BASE}/include/EGL/egl.h)
PLIST.egl=		yes
.  endif
.else
CONFIGURE_ARGS+=	--without-x \
			--disable-xcb \
			--disable-qt \
			--disable-freetype \
			--disable-vdpau
.endif

## DTS support (libdca is non-redistributable)

.if !empty(PKG_OPTIONS:Mdts)
CONFIGURE_ARGS+=	--enable-dca
PLIST.dts=		yes
.  include "../../audio/libdca/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-dca=no
.endif

## VAAPI support
.if !empty(PKG_OPTIONS:Mvaapi)
CONFIGURE_ARGS+=	--enable-libva
PLIST.vaapi=		yes
.include "../../multimedia/libva/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libva
.endif

## LIRC support
.if !empty(PKG_OPTIONS:Mlirc)
CONFIGURE_ARGS+=	--enable-lirc
PLIST.lirc=	yes
.include "../../comms/lirc/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-lirc
.endif
