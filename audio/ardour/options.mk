# $NetBSD: options.mk,v 1.1 2016/06/20 08:17:42 kamil Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ardour

PKG_SUPPORTED_OPTIONS=	alsa jack dummy
PKG_SUGGESTED_OPTIONS=	alsa jack

PLIST_VARS=		alsa jack dummy

.include "../../mk/bsd.options.mk"

.if ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD"
.  if empty(PKG_OPTIONS:Malsa)
.    error ALSA is required on this platform
.  endif
.endif

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
ARDOUR_BACKENDS_ALSA=	yes
PLIST.alsa=	yes
.endif

.if !empty(PKG_OPTIONS:Mjack)
.include "../../audio/jack/buildlink3.mk"
ARDOUR_BACKENDS_JACK=	yes
PLIST.jack=	yes
.endif

# Useful for developers
.if !empty(PKG_OPTIONS:Mdummy)
ARDOUR_BACKENDS_DUMMY=	yes
PLIST.dummy=	yes
.endif

ARDOUR_BACKENDS=	${ARDOUR_BACKENDS_ALSA:Dalsa},${ARDOUR_BACKENDS_JACK:Djack},${ARDOUR_BACKENDS_DUMMY:Ddummy}

WAF_ARGS+=      --with-backends=${ARDOUR_BACKENDS:C/,+$//}
