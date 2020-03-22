# $NetBSD: options.mk,v 1.2 2020/03/22 08:39:48 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.audacious
PKG_SUPPORTED_OPTIONS+=		dbus
PKG_SUGGESTED_OPTIONS+=		dbus

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	dbus

.if !empty(PKG_OPTIONS:Mdbus)
PLIST.dbus=	yes
TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen
.include "../../sysutils/dbus/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif
