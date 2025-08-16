# $NetBSD: options.mk,v 1.1 2025/08/16 00:58:19 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libcupsfilters
PKG_SUPPORTED_OPTIONS=	dbus
PKG_SUGGESTED_OPTIONS=	dbus

.include "../../mk/bsd.options.mk"

#
# DBus support
#
.if !empty(PKG_OPTIONS:Mdbus)
.include "../../sysutils/dbus/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-dbus
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif
