# $NetBSD: options.mk,v 1.8 2011/08/15 01:56:33 schnoebe Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.sane-backends
PKG_SUPPORTED_OPTIONS=		inet6 snmp
PKG_SUGGESTED_OPTIONS=		#defined

.include "../../mk/bsd.options.mk"

# Package-specific option-handling

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Msnmp)
CONFIGURE_ARGS+=	--with-snmp=yes
.include "../../net/net-snmp/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-snmp=no
.endif
