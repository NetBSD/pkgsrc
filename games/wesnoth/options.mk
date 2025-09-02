# $NetBSD: options.mk,v 1.1 2025/09/02 09:33:32 leot Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wesnoth
PKG_SUPPORTED_OPTIONS=	dbus
PKG_SUGGESTED_OPTIONS=	dbus

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbus)
CMAKE_CONFIGURE_ARGS+=	-DENABLE_NOTIFICATIONS=ON
.  include "../../sysutils/dbus/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DENABLE_NOTIFICATIONS=OFF
.endif
