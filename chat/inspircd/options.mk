# $NetBSD: options.mk,v 1.5 2019/01/30 10:16:47 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.inspircd
PKG_SUPPORTED_OPTIONS=		geoip gnutls openssl mysql ldap pcre pgsql sqlite3
PKG_SUGGESTED_OPTIONS=		openssl
PLIST_VARS+=			geoip gnutls openssl mysql ldap pcre pgsql sqlite3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgeoip)
PLIST.geoip=		yes
INSPIRCD_EXTRAS+=	m_geoip.cpp
.include "../../net/GeoIP/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgnutls)
PLIST.gnutls=		yes
CONFIGURE_ARGS+=	--enable-gnutls
.include "../../security/gnutls/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
PLIST.openssl=		yes
CONFIGURE_ARGS+=	--enable-openssl
.include "../../security/openssl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmysql)
PLIST.mysql=		yes
INSPIRCD_EXTRAS+=	m_mysql.cpp
.include "../../mk/mysql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mldap)
PLIST.ldap=		yes
INSPIRCD_EXTRAS+=	m_ldapauth.cpp
INSPIRCD_EXTRAS+=	m_ldapoper.cpp
.include "../../databases/openldap-client/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpcre)
PLIST.pcre=		yes
INSPIRCD_EXTRAS+=	m_regex_pcre.cpp
.include "../../devel/pcre/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
PLIST.pgsql=		yes
INSPIRCD_EXTRAS+=	m_pgsql.cpp
.include "../../mk/pgsql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msqlite3)
PLIST.sqlite3=		yes
INSPIRCD_EXTRAS+=	m_sqlite3.cpp
.include "../../databases/sqlite3/buildlink3.mk"
.endif
