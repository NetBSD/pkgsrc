# $NetBSD: options.mk,v 1.6 2020/10/16 07:42:48 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.mumble
PKG_SUPPORTED_OPTIONS=		alsa dbus jack pulseaudio portaudio
PKG_SUGGESTED_OPTIONS=		dbus portaudio
PKG_SUGGESTED_OPTIONS.Linux=	alsa

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIG_OPTIONS+=	CONFIG+=alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIG_OPTIONS+=	CONFIG+=no-alsa
.endif

.if !empty(PKG_OPTIONS:Mdbus)
CONFIG_OPTIONS+=	CONFIG+=dbus
.else
CONFIG_OPTIONS+=	CONFIG+=no-dbus
.endif

.if !empty(PKG_OPTIONS:Mjack)
CONFIG_OPTIONS+=	CONFIG+=jackaudio
.include "../../audio/jack/buildlink3.mk"
.else
CONFIG_OPTIONS+=	CONFIG+=no-jackaudio
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CONFIG_OPTIONS+=	CONFIG+=pulseaudio
.include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIG_OPTIONS+=	CONFIG+=no-pulseaudio
.endif

.if !empty(PKG_OPTIONS:Mportaudio)
CONFIG_OPTIONS+=	CONFIG+=portaudio
.include "../../audio/portaudio/buildlink3.mk"
.else
CONFIG_OPTIONS+=	CONFIG+=no-portaudio
.endif
