# $NetBSD: options.mk,v 1.1 2025/12/14 10:07:19 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dosbox-staging

PKG_SUPPORTED_OPTIONS+=		alsa fluidsynth
PKG_SUGGESTED_OPTIONS+=		fluidsynth
PKG_SUGGESTED_OPTIONS.Linux+=	alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
MESON_ARGS+=	-Duse_alsa=true
.include "../../audio/alsa-lib/buildlink3.mk"
.else
MESON_ARGS+=	-Duse_alsa=false
.endif

.if !empty(PKG_OPTIONS:Mfluidsynth)
MESON_ARGS+=    -Duse_fluidsynth=true
.include "../../audio/fluidsynth/buildlink3.mk"
.else
MESON_ARGS+=    -Duse_fluidsynth=false
.endif
