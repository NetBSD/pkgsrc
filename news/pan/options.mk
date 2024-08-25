# $NetBSD: options.mk,v 1.2 2024/08/25 06:19:09 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pan
PKG_SUPPORTED_OPTIONS=	dbus
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbus)
CMAKE_CONFIGURE_ARGS+=	-DWANT_DBUS=1
.include "../../sysutils/dbus/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DWANT_DBUS=0
.endif
