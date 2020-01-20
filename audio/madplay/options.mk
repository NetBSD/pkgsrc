# $NetBSD: options.mk,v 1.4 2020/01/20 21:29:07 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.madplay
PKG_SUPPORTED_OPTIONS=		alsa
PKG_SUGGESTED_OPTIONS.Linux=	alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--with-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.endif
