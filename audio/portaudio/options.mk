# $NetBSD: options.mk,v 1.2 2019/10/28 15:32:24 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.portaudio
PKG_SUPPORTED_OPTIONS=		alsa jack debug
PKG_SUGGESTED_OPTIONS.Linux=	alsa

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		alsa
.if !empty(PKG_OPTIONS:Malsa)
PLIST.alsa=		yes
CONFIGURE_ARGS+=	--with-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-alsa
.endif

.if !empty(PKG_OPTIONS:Mjack)
CONFIGURE_ARGS+=	--with-jack
.include "../../audio/jack/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-jack
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug-output
.endif
