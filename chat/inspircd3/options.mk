# $NetBSD: options.mk,v 1.2 2019/05/17 09:59:18 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.inspircd
PKG_SUPPORTED_OPTIONS=		gnutls geoip openssl mysql mbedtls ldap pcre pgsql sqlite3
PKG_SUGGESTED_OPTIONS=		gnutls
PLIST_VARS+=			gnutls geoip openssl mysql mbedtls ldap pcre pgsql sqlite3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgeoip)
PLIST.geoip=		yes
INSPIRCD_EXTRAS+=	m_geo_maxmind.cpp
.include "../../geography/libmaxminddb/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgnutls)
PLIST.gnutls=		yes
INSPIRCD_EXTRAS+=	m_ssl_gnutls.cpp
.include "../../security/gnutls/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
PLIST.openssl=		yes
INSPIRCD_EXTRAS+=	m_ssl_openssl.cpp
.include "../../security/openssl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmbedtls)
PLIST.mbedtls=		yes
INSPIRCD_EXTRAS+=	m_ssl_mbedtls.cpp
.include "../../security/mbedtls/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmysql)
PLIST.mysql=		yes
INSPIRCD_EXTRAS+=	m_mysql.cpp
.include "../../mk/mysql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mldap)
PLIST.ldap=		yes
INSPIRCD_EXTRAS+=	m_ldap.cpp
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
