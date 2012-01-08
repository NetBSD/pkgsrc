# $NetBSD: options.mk,v 1.1.1.1 2012/01/08 05:42:08 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gmtk
PKG_SUPPORTED_OPTIONS=	alsa pulseaudio
PKG_SUGGESTED_OPTIONS=	pulseaudio

.include "../../mk/bsd.options.mk"

#
# PulseAudio device and volume support
#
.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
CONFIGURE_ARGS+=	--with-pulseaudio
.else
CONFIGURE_ARGS+=	--without-pulseaudio
.endif

#
# Read volume from alsa devices
#
.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-alsa
.else
CONFIGURE_ARGS+=	--without-alsa
.endif
