# $NetBSD: options.mk,v 1.3 2019/11/29 17:34:09 nia Exp $

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

PLIST_VARS+=		jack
.if !empty(PKG_OPTIONS:Mjack)
PLIST.jack=		yes
CONFIGURE_ARGS+=	--with-jack
.include "../../audio/jack/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-jack
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug-output
.endif
