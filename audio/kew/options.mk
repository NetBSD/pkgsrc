# $NetBSD: options.mk,v 1.3 2026/02/12 12:55:00 ktnb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kew
PKG_SUPPORTED_OPTIONS=	dbus
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

###
###  Include dbus
###
.if !empty(PKG_OPTIONS:Mdbus)
MAKE_FLAGS+=	USE_DBUS=1
.include "../../sysutils/dbus/buildlink3.mk"
.else
MAKE_FLAGS+=	USE_DBUS=0
.endif
