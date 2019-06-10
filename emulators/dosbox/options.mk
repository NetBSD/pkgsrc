# $NetBSD: options.mk,v 1.1 2019/06/10 12:41:23 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dosbox

PKG_SUPPORTED_OPTIONS+=		alsa
PKG_SUGGESTED_OPTIONS.Linux+=	alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa-midi
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-alsa-midi
.endif
