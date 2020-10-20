# $NetBSD: options.mk,v 1.1 2020/10/20 18:40:31 tnn Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ncspot
PKG_OPTIONS_OPTIONAL_GROUPS=	backend ui
PKG_OPTIONS_GROUP.backend=	alsa portaudio pulseaudio rodio
PKG_OPTIONS_GROUP.ui=		ncursesw termion

PKG_SUPPORTED_OPTIONS=	dbus
PKG_SUGGESTED_OPTIONS=	portaudio ncursesw

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CARGO_FEATURES+=	alsa_backend
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.alsa-lib}/lib
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mportaudio)
CARGO_FEATURES+=	portaudio_backend
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.portaudio}/${BUILDLINK_LIBDIRS.portaudio}
.include "../../audio/portaudio/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CARGO_FEATURES+=	pulseaudio_backend
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.pulseaudio}/lib
.include "../../audio/pulseaudio/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mrodio)
CARGO_FEATURES+=	rodio_backend
.endif

.if !empty(PKG_OPTIONS:Mncursesw)
USE_NCURSES=		yes	# NCURSES_MOUSE_VERSION
CARGO_FEATURES+=	cursive/pancurses-backend
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.ncursesw}/lib
.include "../../devel/ncursesw/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mtermion)
CARGO_FEATURES+=	cursive/termion-backend
.endif

.if !empty(PKG_OPTIONS:Mdbus)
CARGO_FEATURES+=	mpris
CARGO_FEATURES+=	notif
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.dbus}/lib
.  include "../../sysutils/dbus/buildlink3.mk"
.else

.endif
