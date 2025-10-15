# $NetBSD: options.mk,v 1.5 2025/10/15 01:32:00 gutteridge Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.musescore

.include "../../mk/bsd.fast.prefs.mk"

.include "../../audio/jack/platform.mk"
.if ${PLATFORM_SUPPORTS_JACK:tl} == "yes"
PKG_SUPPORTED_OPTIONS+=		jack
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mjack)
CMAKE_CONFIGURE_ARGS+=	-DMUSE_MODULE_AUDIO_JACK=ON
.include "../../audio/jack/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DMUSE_MODULE_AUDIO_JACK=OFF
.endif
