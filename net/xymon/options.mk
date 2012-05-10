# $NetBSD: options.mk,v 1.2 2012/05/10 21:58:38 spz Exp $

PKG_OPTIONS_VAR=        PKG_OPTIONS.xymon
PKG_SUPPORTED_OPTIONS=  ldap snmp ssl
PKG_SUGGESTED_OPTIONS=  ldap ssl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		snmp

# include support for ldap
.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	"--ldapinclude" "${BUILDLINK_PREFIX.openldap-client}/include"
CONFIGURE_ARGS+=	"--ldaplib" "${BUILDLINK_PREFIX.openldap-client}/lib"
CONFIGURE_ENV+=		ENABLELDAP=y
.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ENV+=		ENABLELDAPSSL=y
.endif
.include "../../databases/openldap-client/buildlink3.mk"
.else
CONFIGURE_ENV+=		ENABLELDAP=n
.endif

# include support for snmp
.if !empty(PKG_OPTIONS:Msnmp)
CONFIGURE_ENV+=		SNMP=1
CONFIGURE_ARGS+=	"--snmpconfig" "${BUILDLINK_PREFIX.net-snmp}/bin/net-snmp-config"
.include "../../net/net-snmp/buildlink3.mk"
PLIST.snmp=		yes
.else
CONFIGURE_ENV+=		SNMP=n
.endif

# include support for ssl
.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	"--sslinclude" "${BUILDLINK_PREFIX.openssl}/include"
CONFIGURE_ARGS+=	"--ssllib" "${BUILDLINK_PREFIX.openssl}/lib"
CONFIGURE_ENV+=		ENABLESSL=y
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ENV+=		ENABLESSL=n
.endif
