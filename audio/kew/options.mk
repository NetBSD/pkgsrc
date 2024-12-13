# $NetBSD: options.mk,v 1.2 2024/12/13 15:12:57 ktnb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kew
PKG_SUPPORTED_OPTIONS=	dbus
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

###
###  Include dbus
###
.if !empty(PKG_OPTIONS:Mdbus)
.include "../../sysutils/dbus/buildlink3.mk"
.endif
