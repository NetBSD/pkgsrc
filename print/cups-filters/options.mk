# $NetBSD: options.mk,v 1.1 2017/12/17 21:16:07 leot Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.cups-filters
PKG_SUPPORTED_OPTIONS=	avahi dbus
PKG_SUGGESTED_OPTIONS=	avahi dbus

.include "../../mk/bsd.options.mk"

#
# Avahi support
#
.if !empty(PKG_OPTIONS:Mavahi)
.include "../../net/avahi/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-avahi
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif

#
# DBus support
#
.if !empty(PKG_OPTIONS:Mdbus)
.include "../../sysutils/dbus/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-dbus
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif
