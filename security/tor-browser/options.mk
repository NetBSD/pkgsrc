# $NetBSD: options.mk,v 1.10 2020/11/18 22:38:21 riastradh Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tor-browser

PKG_SUPPORTED_OPTIONS+=	debug debug-info mozilla-jemalloc webrtc
PKG_SUPPORTED_OPTIONS+=	alsa pulseaudio dbus

.if ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS+=	pulseaudio mozilla-jemalloc dbus webrtc
.else
PKG_SUGGESTED_OPTIONS+=	dbus
.endif

.if ${OPSYS} == "NetBSD" && empty(OS_VERSION:M[0-8].*)
PKG_SUGGESTED_OPTIONS+=	webrtc
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

.if !empty(PKG_OPTIONS:Mmozilla-jemalloc)
CONFIGURE_ARGS+=	--enable-jemalloc
CONFIGURE_ARGS+=	--enable-replace-malloc
.else
CONFIGURE_ARGS+=	--disable-jemalloc
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug="-g -Og"
CONFIGURE_ARGS+=	--disable-optimize
CONFIGURE_ARGS+=	--enable-debug-js-modules
CONFIGURE_ARGS+=	--disable-install-strip
.else
.  if !empty(PKG_OPTIONS:Mdebug-info)
CONFIGURE_ARGS+=	--enable-debug-symbols
CONFIGURE_ARGS+=	--enable-optimize=-O2
CONFIGURE_ARGS+=	--disable-install-strip
.  else
CONFIGURE_ARGS+=	--disable-debug-symbols
CONFIGURE_ARGS+=	--enable-optimize=-O2
CONFIGURE_ARGS+=	--enable-install-strip
.  endif
CONFIGURE_ARGS+=	--disable-debug
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pulseaudio
.else
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif

.if !empty(PKG_OPTIONS:Mdbus)
.include "../../sysutils/dbus-glib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-dbus
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if !empty(PKG_OPTIONS:Mwebrtc)
.include "../../graphics/libv4l/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-webrtc
.else
CONFIGURE_ARGS+=	--disable-webrtc
.endif
