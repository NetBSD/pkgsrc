# $NetBSD: options.mk,v 1.1 2018/12/18 17:08:20 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.mednafen

PKG_SUPPORTED_OPTIONS+=		alsa jack
PKG_SUGGESTED_OPTIONS.Linux+=	alsa

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
