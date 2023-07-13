# $NetBSD: options.mk,v 1.1 2023/07/13 20:38:53 pin Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.spotifyd
PKG_OPTIONS_OPTIONAL_GROUPS=	backend
PKG_OPTIONS_GROUP.backend=	alsa portaudio pulseaudio rodio

PKG_SUGGESTED_OPTIONS=		portaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CARGO_FEATURES+=	alsa_backend
RUSTFLAGS+=		-C link-arg=-L${BUILDLINK_PREFIX.alsa-lib}/lib
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.alsa-lib}/lib
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mportaudio)
CARGO_FEATURES+=	portaudio_backend
RUSTFLAGS+=		-C link-arg=-L${BUILDLINK_PREFIX.portaudio}/lib
RUSTFLAGS+=		-C link-arg=-L${BUILDLINK_PREFIX.portaudio}/${BUILDLINK_LIBDIRS.portaudio}
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.portaudio}/lib
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.portaudio}/${BUILDLINK_LIBDIRS.portaudio}
.include "../../audio/portaudio/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CARGO_FEATURES+=	pulseaudio_backend
RUSTFLAGS+=		-C link-arg=-L${BUILDLINK_PREFIX.pulseaudio}/lib
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.pulseaudio}/lib
.include "../../audio/pulseaudio/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mrodio)
CARGO_FEATURES+=	rodio_backend
.endif
