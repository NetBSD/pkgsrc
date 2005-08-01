# $NetBSD: options.mk,v 1.3 2005/08/01 11:58:33 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.net-snmp
PKG_SUPPORTED_OPTIONS=		ssl
# remove after pkgsrc-2005Q3
PKG_OPTIONS_LEGACY_VARS+=	NET_SNMP_USE_SSL:ssl

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "SunOS" && ${OPSYS} != "Darwin"
# net-snmp doesn't do IPv6 on Solaris & Darwin
PKG_SUPPORTED_OPTIONS+=	inet6
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
PLIST_SUBST+=   	IPV6H=
.else
CONFIGURE_ARGS+=	--disable-ipv6
PLIST_SUBST+=   	IPV6H="@comment "
.endif

.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl
.endif
