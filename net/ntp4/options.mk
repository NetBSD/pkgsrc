# $NetBSD: options.mk,v 1.4 2020/06/21 15:10:47 taca Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ntp4
PKG_SUPPORTED_OPTIONS=	inet6 snmp
PKG_SUGGESTED_OPTIONS=

PLIST_VARS+=	ntpsnmpd

.if empty(MISSING_FEATURES:Minet6)
PKG_SUGGESTED_OPTIONS+=	inet6
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Msnmp)
CONFIGURE_ARGS+=	--with-ntpsnmpd
PLIST.ntpsnmpd=		yes
USE_TOOLS+=		perl
.  include "../../net/net-snmp/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ntpsnmpd
CONFIGURE_ARGS+=	--with-net-snmp-config=false
.endif
