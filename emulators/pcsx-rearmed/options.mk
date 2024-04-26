# $NetBSD: options.mk,v 1.1 2024/04/26 09:10:10 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.pcsx-rearmed
PKG_SUPPORTED_OPTIONS=		alsa pulseaudio
PKG_SUGGESTED_OPTIONS.Linux=	alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
PCSX_SOUND_DRIVERS+=	alsa
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
PCSX_SOUND_DRIVERS+=	pulseaudio
.  include "../../audio/pulseaudio/buildlink3.mk"
.endif
