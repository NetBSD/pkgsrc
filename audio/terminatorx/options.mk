# $NetBSD: options.mk,v 1.1 2019/10/05 15:52:43 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.terminatorx
PKG_SUPPORTED_OPTIONS=		alsa jack pulseaudio
PKG_SUGGESTED_OPTIONS.Linux=	alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

.if !empty(PKG_OPTIONS:Mjack)
CONFIGURE_ARGS+=	--enable-jack
.include "../../audio/jack/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-jack
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CONFIGURE_ARGS+=	--enable-pulse
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pulse
.endif
