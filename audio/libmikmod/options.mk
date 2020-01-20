# $NetBSD: options.mk,v 1.3 2020/01/20 21:26:52 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libmikmod
PKG_SUPPORTED_OPTIONS=	pulseaudio

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "Linux"
PKG_SUPPORTED_OPTIONS+=	alsa
PKG_SUGGESTED_OPTIONS+=	alsa
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CONFIGURE_ARGS+=	--enable-pulseaudio
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif
