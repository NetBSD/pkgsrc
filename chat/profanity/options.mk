# $NetBSD: options.mk,v 1.3 2026/11/19 15:32:32 ktnb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.profanity
PKG_SUPPORTED_OPTIONS=	dbus
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

# dbus
.if !empty(PKG_OPTIONS:Mdbus)
MESON_ARGS+=		-Dnotifications=enabled
MESON_ARGS+=		-Dtray=enabled
.include "../../sysutils/dbus/buildlink3.mk"
.endif
