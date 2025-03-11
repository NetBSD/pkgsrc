# $NetBSD: options.mk,v 1.1 2025/03/11 09:57:10 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.schismtracker
PKG_SUPPORTED_OPTIONS=		alsa jack
PKG_SUGGESTED_OPTIONS.Linux=	alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--with-alsa
CONFIGURE_ARGS+=	--enable-alsa-linking
.  include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-alsa
.endif

.if !empty(PKG_OPTIONS:Mjack)
CONFIGURE_ARGS+=	--with-jack
CONFIGURE_ARGS+=	--enable-jack-linking
.  include "../../audio/jack/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-jack
.endif
