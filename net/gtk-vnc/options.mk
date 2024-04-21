# $NetBSD: options.mk,v 1.16 2024/04/21 14:47:51 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtk-vnc
PKG_SUPPORTED_OPTIONS=	pulseaudio sasl
PKG_SUGGESTED_OPTIONS=	pulseaudio sasl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msasl)
.include "../../security/cyrus-sasl/buildlink3.mk"
.endif

PLIST_VARS+=	pulseaudio
.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
MESON_ARGS+=		-D pulseaudio=enabled
PLIST.pulseaudio=	yes
.else
MESON_ARGS+=		-D pulseaudio=disabled
.endif
