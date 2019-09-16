# $NetBSD: options.mk,v 1.3 2019/09/16 22:46:20 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.mumble
PKG_SUPPORTED_OPTIONS=		alsa pulseaudio portaudio
PKG_SUGGESTED_OPTIONS=		portaudio
PKG_SUGGESTED_OPTIONS.Linux=	alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIG_OPTIONS+=	CONFIG+=alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIG_OPTIONS+=	CONFIG+=no-alsa
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIG_OPTIONS+=	CONFIG+=no-pulseaudio
.endif

.if !empty(PKG_OPTIONS:Mportaudio)
.include "../../audio/portaudio-devel/buildlink3.mk"
.else
CONFIG_OPTIONS+=	CONFIG+=no-portaudio
.endif
