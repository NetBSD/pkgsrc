# $NetBSD: options.mk,v 1.1 2024/04/26 09:04:31 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.picodrive
PKG_SUPPORTED_OPTIONS=		alsa pulseaudio
PKG_SUGGESTED_OPTIONS.Linux=	alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
SOUND_DRIVERS+=		alsa
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
SOUND_DRIVERS+=		pulseaudio
.  include "../../audio/pulseaudio/buildlink3.mk"
.endif
