# $NetBSD: options.mk,v 1.4 2020/01/20 22:12:21 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.allegro
PKG_SUPPORTED_OPTIONS=		alsa jack
PKG_SUGGESTED_OPTIONS.Linux=	alsa

.include "../../mk/bsd.options.mk"

PLIST_SRC+=	PLIST

.if !empty(PKG_OPTIONS:Malsa)
PLIST_SRC+=	PLIST.alsa
CFLAGS.NetBSD+=	-DESTRPIPE=EPIPE
CMAKE_ARGS+=	-DWANT_ALSA=1
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWANT_ALSA=0
.endif

.if !empty(PKG_OPTIONS:Mjack)
PLIST_SRC+=	PLIST.jack
CMAKE_ARGS+=	-DWANT_JACK=1
.include "../../audio/jack/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWANT_JACK=0
.endif
