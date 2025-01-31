# $NetBSD: options.mk,v 1.7 2025/01/31 17:15:11 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ardour
PKG_SUPPORTED_OPTIONS=	alsa jack

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS=	alsa jack
.else
PKG_SUGGESTED_OPTIONS=	jack
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
ARD_BACKENDS+=	alsa
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mjack)
ARD_BACKENDS+=	jack
.  include "../../audio/jack/buildlink3.mk"
.endif

#
# currently windows-only, would be nice to have
#
#.if !empty(PKG_OPTIONS:Mportaudio)
#ARD_BACKENDS+=	portaudio
#.include "../../audio/portaudio/buildlink3.mk"
#.endif
