# $NetBSD: options.mk,v 1.1 2019/05/03 17:14:27 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.inspircd
PKG_SUPPORTED_OPTIONS=		gnutls geoip openssl mysql mbedtls ldap pcre pgsql sqlite3
PKG_SUGGESTED_OPTIONS=		gnutls
PLIST_VARS+=			gnutls geoip openssl mysql mbedtls ldap pcre pgsql sqlite3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgeoip)
PLIST.geoip=		yes
INSPIRCD_EXTRAS_ON+=	m_geo_maxmind.cpp
.include "../../geography/libmaxminddb/buildlink3.mk"
.else
INSPIRCD_EXTRAS_OFF+=	m_geo_maxmind.cpp
.endif

.if !empty(PKG_OPTIONS:Mgnutls)
PLIST.gnutls=		yes
INSPIRCD_EXTRAS_ON+=	m_ssl_gnutls.cpp
.include "../../security/gnutls/buildlink3.mk"
.else
INSPIRCD_EXTRAS_OFF+=	m_ssl_gnutls.cpp
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
PLIST.openssl=		yes
INSPIRCD_EXTRAS_ON+=	m_ssl_openssl.cpp
.include "../../security/openssl/buildlink3.mk"
.else
INSPIRCD_EXTRAS_OFF+=	m_ssl_openssl.cpp
.endif

.if !empty(PKG_OPTIONS:Mmbedtls)
PLIST.mbedtls=		yes
INSPIRCD_EXTRAS_ON+=	m_ssl_mbedtls.cpp
.include "../../security/mbedtls/buildlink3.mk"
.else
INSPIRCD_EXTRAS_OFF+=	m_ssl_mbedtls.cpp
.endif

.if !empty(PKG_OPTIONS:Mmysql)
PLIST.mysql=		yes
INSPIRCD_EXTRAS_ON+=	m_mysql.cpp
.include "../../mk/mysql.buildlink3.mk"
.else
INSPIRCD_EXTRAS_OFF+=	m_mysql.cpp
.endif

.if !empty(PKG_OPTIONS:Mldap)
PLIST.ldap=		yes
INSPIRCD_EXTRAS_ON+=	m_mysql.cpp
.include "../../databases/openldap-client/buildlink3.mk"
.else
INSPIRCD_EXTRAS_OFF+=	m_mysql.cpp
.endif

.if !empty(PKG_OPTIONS:Mpcre)
PLIST.pcre=		yes
INSPIRCD_EXTRAS_ON+=	m_regex_pcre.cpp
.include "../../devel/pcre/buildlink3.mk"
.else
INSPIRCD_EXTRAS_OFF+=	m_regex_pcre.cpp
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
PLIST.pgsql=		yes
INSPIRCD_EXTRAS_ON+=	m_pgsql.cpp
.include "../../mk/pgsql.buildlink3.mk"
.else
INSPIRCD_EXTRAS_OFF+=	m_pgsql.cpp
.endif

.if !empty(PKG_OPTIONS:Msqlite3)
PLIST.sqlite3=		yes
INSPIRCD_EXTRAS_ON+=	m_sqlite3.cpp
.include "../../databases/sqlite3/buildlink3.mk"
.else
INSPIRCD_EXTRAS_OFF+=	m_sqlite3.cpp
.endif
