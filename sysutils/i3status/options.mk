# $NetBSD: options.mk,v 1.1 2022/04/14 06:36:27 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.i3status
PKG_SUPPORTED_OPTIONS=		pulseaudio
PKG_SUGGESTED_OPTIONS.Linux=	pulseaudio

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpulseaudio)
MESON_ARGS+=	-Dpulseaudio=true
.  include "../../audio/pulseaudio/buildlink3.mk"
.else
MESON_ARGS+=	-Dpulseaudio=false
.endif
