# $NetBSD: options.mk,v 1.1 2019/12/07 10:24:02 mrg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.csound6
PKG_SUPPORTED_OPTIONS=	pulseaudio
PKG_SUGGESTED_OPTIONS=	pulseaudio

.include "../../mk/bsd.options.mk"

PLIST_VARS+=            pulseaudio
.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
PLIST.pulseaudio=	yes
.endif
