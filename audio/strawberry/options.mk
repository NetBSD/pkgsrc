# $NetBSD: options.mk,v 1.4 2026/05/19 14:36:35 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.strawberry
PKG_SUPPORTED_OPTIONS=		pulseaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpulseaudio)
CMAKE_CONFIGURE_ARGS+=	-DENABLE_PULSE=ON
.  include "../../audio/pulseaudio/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DENABLE_PULSE=OFF
.endif
