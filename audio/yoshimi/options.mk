# $NetBSD: options.mk,v 1.1 2026/11/14 07:23:20 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.yoshimi
PKG_SUPPORTED_OPTIONS=		alsa jack
PKG_SUGGESTED_OPTIONS.Linux=	alsa
PKG_SUGGESTED_OPTIONS.NetBSD=	jack

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mjack)
.  include "../../audio/jack/buildlink3.mk"
.endif
