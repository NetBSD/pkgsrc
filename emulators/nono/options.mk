# $NetBSD: options.mk,v 1.1 2026/08/30 20:25:18 jun Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nono

PKG_SUPPORTED_OPTIONS+=		alsa pulseaudio
PKG_SUGGESTED_OPTIONS=
PKG_SUGGESTED_OPTIONS.Linux+=	alsa pulseaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--with-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--enable-pulseaudio
.include "../../audio/pulseaudio/buildlink3.mk"
.endif
