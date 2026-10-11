# $NetBSD: options.mk,v 1.3 2026/10/11 07:51:10 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.aubio
PKG_SUPPORTED_OPTIONS=	jack alsa
PKG_SUGGESTED_OPTIONS=	jack alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjack)
.  include "../../audio/jack/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Malsa)
.  include "../../audio/alsa-lib/buildlink3.mk"
.  include "../../audio/jack/buildlink3.mk"
.endif
