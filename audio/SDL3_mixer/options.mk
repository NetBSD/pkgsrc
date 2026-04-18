# $NetBSD: options.mk,v 1.1 2026/04/18 15:08:09 js Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.SDL3_mixer
PKG_SUPPORTED_OPTIONS=	fluidsynth

.include "../../mk/bsd.options.mk"

# default for MIDI support is timidity
.if !empty(PKG_OPTIONS:Mfluidsynth)
.include "../../audio/fluidsynth/buildlink3.mk"
CONFIGURE_ARGS+=	-DSDLMIXER_MIDI_FLUIDSYNTH=ON
.else
CONFIGURE_ARGS+=	-DSDLMIXER_MIDI_FLUIDSYNTH=OFF
.endif
