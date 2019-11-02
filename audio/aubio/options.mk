# $NetBSD: options.mk,v 1.2 2019/11/02 21:09:12 rillig Exp $
#

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
