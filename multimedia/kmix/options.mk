# $NetBSD: options.mk,v 1.3 2021/10/25 03:55:29 mrg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kmix
PKG_SUPPORTED_OPTIONS=	pulseaudio
PKG_SUGGESTED_OPTIONS=	pulseaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.endif
