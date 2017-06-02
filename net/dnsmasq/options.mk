# $NetBSD: options.mk,v 1.4 2017/06/02 08:37:49 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dnsmasq
PKG_SUPPORTED_OPTIONS=	dbus inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	dbus

.if !empty(PKG_OPTIONS:Mdbus)
USE_TOOLS+=	pkg-config
CFLAGS+=	-DHAVE_DBUS
CONF_FILES+=	${EGDIR}/dnsmasq-dbus.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/dnsmasq-dbus.conf
PLIST.dbus=	yes
.include "../../sysutils/dbus/buildlink3.mk"
.endif

.if empty(PKG_OPTIONS:Minet6)
CFLAGS+=	-DNO_IPV6
.endif
