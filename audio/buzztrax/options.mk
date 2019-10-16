# $NetBSD: options.mk,v 1.1 2019/10/16 11:18:11 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.buzztrax
PKG_SUPPORTED_OPTIONS=		alsa
PKG_SUGGESTED_OPTIONS.Linux=	alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.endif
