# $NetBSD: options.mk,v 1.3 2018/11/01 21:12:40 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.SDL2_mixer
PKG_SUPPORTED_OPTIONS=	fluidsynth

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfluidsynth)
.include "../../audio/fluidsynth/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-music-midi-fluidsynth=yes
.else
CONFIGURE_ARGS+=	--enable-music-midi-fluidsynth=no
.endif
