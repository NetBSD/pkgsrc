# $NetBSD: options.mk,v 1.8 2024/05/06 08:33:49 jperkin Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ncspot
PKG_OPTIONS_OPTIONAL_GROUPS=	backend ui
PKG_OPTIONS_GROUP.backend=	alsa portaudio pulseaudio rodio
PKG_OPTIONS_GROUP.ui=		ncursesw termion

PKG_SUPPORTED_OPTIONS=	dbus xcb
PKG_SUGGESTED_OPTIONS=	portaudio termion

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
CARGO_FEATURES+=	cursive/pancurses-backend
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.ncurses}/lib
.include "../../devel/ncurses/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mtermion)
CARGO_FEATURES+=	termion_backend
.endif

.if !empty(PKG_OPTIONS:Mdbus)
CARGO_FEATURES+=	mpris
CARGO_FEATURES+=	notify
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.dbus}/lib
.include "../../sysutils/dbus/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mxcb)
CARGO_FEATURES+=	share_clipboard
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libxcb}/lib
RUSTFLAGS+=		-C link-arg=-L${BUILDLINK_PREFIX.libxcb}/lib
.include "../../x11/libxcb/buildlink3.mk"
.endif
