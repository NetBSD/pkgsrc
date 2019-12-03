# $NetBSD: options.mk,v 1.5 2019/12/03 12:31:22 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ardour
PKG_SUPPORTED_OPTIONS=	alsa jack

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS=	alsa jack
.else
PKG_SUGGESTED_OPTIONS=	jack
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	alsa
.if !empty(PKG_OPTIONS:Malsa)
PLIST.alsa=	yes
ARD_BACKENDS+=	alsa
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif

PLIST_VARS+=	jack
.if !empty(PKG_OPTIONS:Mjack)
PLIST.jack=	yes
ARD_BACKENDS+=	jack
BUILDLINK_API_DEPENDS.jack+=	jack>=0.125.0nb2
.  include "../../audio/jack/buildlink3.mk"
.endif

#
# currently windows-only, would be nice to have
#
#.if !empty(PKG_OPTIONS:Mportaudio)
#ARD_BACKENDS+=	portaudio
#.include "../../audio/portaudio/buildlink3.mk"
#.endif
