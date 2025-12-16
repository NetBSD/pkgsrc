# $NetBSD: options.mk,v 1.2 2025/12/16 09:44:45 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dosbox-staging

PKG_SUPPORTED_OPTIONS=		alsa fluidsynth opengl slirp zlib-ng
PKG_SUGGESTED_OPTIONS=		${PKG_SUPPORTED_OPTIONS:S/alsa//}
PKG_SUGGESTED_OPTIONS.Linux+=	alsa

.include "../../mk/bsd.options.mk"

###
### Enable ALSA MIDI support.
###
.if !empty(PKG_OPTIONS:Malsa)
MESON_ARGS+=	-Duse_alsa=true
.  include "../../audio/alsa-lib/buildlink3.mk"
.else
MESON_ARGS+=	-Duse_alsa=false
.endif

###
### Enable built-in MIDI support via FluidSynth.
###
.if !empty(PKG_OPTIONS:Mfluidsynth)
MESON_ARGS+=	-Duse_fluidsynth=true
.  include "../../audio/fluidsynth/buildlink3.mk"
.else
MESON_ARGS+=	-Duse_fluidsynth=false
.endif

##
## Enable OpenGL support.
##
.if !empty(PKG_OPTIONS:Mopengl)
.  include "../../graphics/MesaLib/buildlink3.mk"
MESON_ARGS+=	-Duse_opengl=true
.else
MESON_ARGS+=	-Duse_opengl=false
.endif

###
### Enable Ethernet emulation using libslirp.
###
.if !empty(PKG_OPTIONS:Mslirp)
MESON_ARGS+=	-Duse_slirp=true
.  include "../../net/libslirp/buildlink3.mk"
.else
MESON_ARGS+=	-Duse_slirp=false
.endif

###
### Enable zlib-ng with SIMD optimization.
###
.if !empty(PKG_OPTIONS:Mzlib-ng)
MESON_ARGS+=	-Duse_zlib_ng=native
.  include "../../archivers/zlib-ng/buildlink3.mk"
.else
MESON_ARGS+=	-Duse_zlib_ng=false
.endif
