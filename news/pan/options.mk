# $NetBSD: options.mk,v 1.1 2024/06/06 18:51:13 rhialto Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pan
PKG_SUPPORTED_OPTIONS=	dbus
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbus)
CMAKE_ARGS+=	-DWANT_DBUS=1
.include "../../sysutils/dbus/buildlink3.mk"
.else
CMAKE_ARGS+=	-DWANT_DBUS=0
.endif
