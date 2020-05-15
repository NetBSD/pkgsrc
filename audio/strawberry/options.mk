# $NetBSD: options.mk,v 1.1 2020/05/15 17:38:35 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.strawberry
PKG_SUPPORTED_OPTIONS=		pulseaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_ARGS+=	-DLIBPULSE=ON
.  include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_ARGS+=	-DLIBPULSE=OFF
.endif
