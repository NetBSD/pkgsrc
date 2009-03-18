# $NetBSD: options.mk,v 1.2 2009/03/18 21:58:26 roy Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dnsmasq

PKG_SUPPORTED_OPTIONS=	dbus inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbus)
USE_TOOLS+=	pkg-config
CFLAGS+=	-DHAVE_DBUS
.include "../../sysutils/dbus/buildlink3.mk"
.endif

.if empty(PKG_OPTIONS:Minet6)
CFLAGS+=	-DNO_IPV6
.endif
