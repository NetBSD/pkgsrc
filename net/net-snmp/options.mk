# $NetBSD: options.mk,v 1.8 2009/03/18 22:50:28 adrianp Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.net-snmp
PKG_SUPPORTED_OPTIONS=		ssl snmp-unprived snmp-nokmem

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "SunOS" && ${OPSYS} != "Darwin"
# net-snmp doesn't do IPv6 on Solaris & Darwin
PKG_SUPPORTED_OPTIONS+=	inet6
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		inet6
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
PLIST.inet6=		yes
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl
.else
CONFIGURE_ARGS+=	--without-openssl
.endif

.if !empty(PKG_OPTIONS:Msnmp-nokmem)
CONFIGURE_ARGS+=	--without-kmem-usage
.endif

.if !empty(PKG_OPTIONS:Msnmp-unprived)
CONFIGURE_ARGS+=	--without-root-access
.endif
