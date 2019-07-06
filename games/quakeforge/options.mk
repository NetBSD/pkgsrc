# $NetBSD: options.mk,v 1.1 2019/07/06 22:53:24 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.quakeforge
PKG_SUPPORTED_OPTIONS=		alsa jack
PKG_SUGGESTED_OPTIONS=
PKG_SUGGESTED_OPTIONS.Linux=	alsa

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	alsa
.if !empty(PKG_OPTIONS:Malsa)
PLIST.alsa=		yes
CONFIGURE_ARGS+=	--enable-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

PLIST_VARS+=	jack
.if !empty(PKG_OPTIONS:Mjack)
PLIST.jack=		yes
CONFIGURE_ARGS+=	--enable-jack
.include "../../audio/jack/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-jack
.endif
