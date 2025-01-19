# $NetBSD: options.mk,v 1.4 2025/01/19 18:13:51 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.SDL2_mixer
PKG_SUPPORTED_OPTIONS=	fluidsynth

.include "../../mk/bsd.options.mk"

# default for MIDI support is timidity
.if !empty(PKG_OPTIONS:Mfluidsynth)
.include "../../audio/fluidsynth/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-music-midi-fluidsynth=yes
.else
CONFIGURE_ARGS+=	--enable-music-midi-fluidsynth=no
.endif
