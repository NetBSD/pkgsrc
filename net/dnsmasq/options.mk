# $NetBSD: options.mk,v 1.5 2018/10/27 07:57:10 maya Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dnsmasq
PKG_SUPPORTED_OPTIONS=	dbus inet6 dnssec
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

.if !empty(PKG_OPTIONS:Mdnssec)
USE_TOOLS+=	pkg-config
CFLAGS+=	-DHAVE_DNSSEC
.include "../../security/nettle/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.endif
