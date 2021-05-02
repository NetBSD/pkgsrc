# $NetBSD: options.mk,v 1.3 2021/05/02 11:06:12 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.audacious
PKG_SUPPORTED_OPTIONS+=		dbus
PKG_SUGGESTED_OPTIONS+=		dbus

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	dbus

.if !empty(PKG_OPTIONS:Mdbus)
PLIST.dbus=	yes
USE_TOOLS+=	gdbus-codegen
.include "../../sysutils/dbus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif
