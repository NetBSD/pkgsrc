# $NetBSD: options.mk,v 1.2 2019/02/05 19:10:50 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.anope
PKG_SUPPORTED_OPTIONS=		gnutls openssl mysql ldap pcre sqlite3
PKG_SUGGESTED_OPTIONS=		openssl
PLIST_VARS+=			gnutls openssl mysql ldap pcre sqlite3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
PLIST.gnutls=	yes
ANOPE_EXTRAS+=	m_ssl_gnutls.cpp
.include "../../security/gnutls/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
PLIST.openssl=	yes
ANOPE_EXTRAS+=	m_ssl_openssl.cpp
.include "../../security/openssl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmysql)
PLIST.mysql=	yes
ANOPE_EXTRAS+=	m_mysql.cpp
.include "../../mk/mysql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mldap)
PLIST.ldap=	yes
ANOPE_EXTRAS+=	m_ldap.cpp
ANOPE_EXTRAS+=	m_ldap_authentication.cpp
.include "../../databases/openldap-client/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpcre)
PLIST.pcre=	yes
ANOPE_EXTRAS+=	m_regex_pcre.cpp
.include "../../devel/pcre/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msqlite3)
PLIST.sqlite3=	yes
ANOPE_EXTRAS+=	m_sqlite.cpp
.include "../../databases/sqlite3/buildlink3.mk"
.endif
