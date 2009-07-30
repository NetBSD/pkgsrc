# $NetBSD: options.mk,v 1.1 2009/07/30 16:07:08 zafer Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.filezilla
PKG_SUPPORTED_OPTIONS+=		dbus
PKG_SUGGESTED_OPTIONS+=		dbus

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbus)
CONFIGURE_ARGS+=	--with-dbus
.  include "../../sysutils/dbus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-dbus
.endif
