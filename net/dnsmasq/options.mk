# $NetBSD: options.mk,v 1.1 2008/12/19 07:53:43 roy Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dnsmasq

PKG_SUPPORTED_OPTIONS=	dbus inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdbus)
CFLAGS+=	-DHAVE_DBUS
.include "../../sysutils/dbus/buildlink3.mk"
.endif

.if empty(PKG_OPTIONS:Minet6)
CFLAGS+=	-DNO_IPV6
.endif
