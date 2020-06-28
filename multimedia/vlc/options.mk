# $NetBSD: options.mk,v 1.38 2020/06/28 15:23:38 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.vlc
PKG_SUPPORTED_OPTIONS=		alsa avahi dbus debug dts jack pulseaudio
PKG_SUPPORTED_OPTIONS+=		vlc-skins qt5 x11
PKG_SUGGESTED_OPTIONS=		dbus qt5
PKG_SUGGESTED_OPTIONS.Linux+=	alsa

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
PKG_SUGGESTED_OPTIONS+=		x11
.endif

### Add VAAPI if it is available
.include "../../multimedia/libva/available.mk"
.if ${VAAPI_AVAILABLE} == "yes"
PKG_SUPPORTED_OPTIONS+= vaapi
PKG_SUGGESTED_OPTIONS+=	vaapi
.endif

### Add VDPAU if it is available
.include "../../multimedia/libvdpau/available.mk"
.if ${VDPAU_AVAILABLE} == "yes"
PKG_SUPPORTED_OPTIONS+= vdpau
PKG_SUGGESTED_OPTIONS+= vdpau
.endif

### Add LIRC if it is available
.include "../../comms/lirc/available.mk"
.if ${LIRC_AVAILABLE} == "yes"
PKG_SUPPORTED_OPTIONS+= lirc
PKG_SUGGESTED_OPTIONS+=	lirc
.endif

###
.include "../../mk/bsd.options.mk"

## ALSA support

PLIST_VARS+=	alsa
.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
PLIST.alsa=	yes
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

## Avahi support

PLIST_VARS+=	avahi
.if !empty(PKG_OPTIONS:Mavahi)
CONFIGURE_ARGS+=	--enable-avahi
.include "../../net/avahi/buildlink3.mk"
PLIST.avahi=	yes
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

## PulseAudio support

PLIST_VARS+=		pulseaudio
.if !empty(PKG_OPTIONS:Mpulseaudio)
CONFIGURE_ARGS+=	--enable-pulse
.include "../../audio/pulseaudio/buildlink3.mk"
PLIST.pulseaudio=	yes
.else
CONFIGURE_ARGS+=	--disable-pulse
.endif

## Jack Audio Connection Kit support

PLIST_VARS+=		jack
.if !empty(PKG_OPTIONS:Mjack)
CONFIGURE_ARGS+=	--enable-jack
.include "../../audio/jack/buildlink3.mk"
PLIST.jack=		yes
.else
CONFIGURE_ARGS+=	--disable-jack
.endif

## DBUS message bus support

PLIST_VARS+=		dbus
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

PLIST_VARS+=		vlc-skins
.if !empty(PKG_OPTIONS:Mvlc-skins)
CONFIGURE_ARGS+=	--enable-skins2
PLIST.vlc-skins=	yes
INSTALLATION_DIRS+=	share/vlc/skins2
.else
CONFIGURE_ARGS+=	--disable-skins2
.endif

## QT5 frontend

PLIST_VARS+=		qt5
.if !empty(PKG_OPTIONS:Mqt5)
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
PLIST.qt5=		yes
CONFIGURE_ARGS+=	--enable-qt
.else
CONFIGURE_ARGS+=	--disable-qt
.endif

## X11 video output

PLIST_VARS+=		x11
.if !empty(PKG_OPTIONS:Mx11)
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
PLIST.x11=		yes
CONFIGURE_ARGS+=	--enable-xcb
CONFIGURE_ARGS+=	--enable-xvideo
.else
CONFIGURE_ARGS+=	--disable-xcb
CONFIGURE_ARGS+=	--disable-xvideo
.endif

.if !empty(PKG_OPTIONS:Mx11) && !empty(PKG_OPTIONS:Mqt5)
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.endif

## DTS support (libdca is non-redistributable)

PLIST_VARS+=		dts
.if !empty(PKG_OPTIONS:Mdts)
CONFIGURE_ARGS+=	--enable-dca
PLIST.dts=		yes
.  include "../../audio/libdca/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-dca=no
.endif

## VAAPI support
PLIST_VARS+=		vaapi
.if !empty(PKG_OPTIONS:Mvaapi)
CONFIGURE_ARGS+=	--enable-libva
PLIST.vaapi=		yes
.include "../../multimedia/libva/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libva
.endif

## VDPAU support
PLIST_VARS+=		vdpau
.if !empty(PKG_OPTIONS:Mvdpau)
CONFIGURE_ARGS+=	--enable-vdpau
PLIST.vdpau=		yes
.include "../../multimedia/libvdpau/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-vdpau
.endif

## LIRC support
PLIST_VARS+=		lirc
.if !empty(PKG_OPTIONS:Mlirc)
CONFIGURE_ARGS+=	--enable-lirc
PLIST.lirc=	yes
.include "../../comms/lirc/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-lirc
.endif
