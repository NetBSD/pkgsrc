# $NetBSD: options.mk,v 1.1 2016/06/02 09:18:19 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mpg321
PKG_SUPPORTED_OPTIONS=	alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa=yes
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-alsa=no
.endif
