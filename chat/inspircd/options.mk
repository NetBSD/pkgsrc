# $NetBSD: options.mk,v 1.3 2016/07/10 09:52:21 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.inspircd

PKG_SUPPORTED_OPTIONS=	inet6 ssl gnutls kqueue epoll inspircd-remoteinet6
PKG_SUPPORTED_OPTIONS+=	pcre inspircd-ziplinks inspircd-sqlauth
PKG_SUPPORTED_OPTIONS+=	inspircd-sqllog inspircd-sqloper
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

###
### Dependency notes:
###
### sql 	= mysql, pgsql, sqlite3
### sqlutils 	= m_sqlutils.cpp m_sqlutils.h
###
### sqloper 	needs sql sqlutils
### sqllog	needs sql
### sqlauth	needs sql sqlutils
###

###
### Enable kqueue support
###
.if !empty(PKG_OPTIONS:Mkqueue)
CONFIGURE_ARGS+=	--enable-kqueue
.else
CONFIGURE_ARGS+=	--disable-kqueue
.endif

###
### Enable epoll support
###
.if !empty(PKG_OPTIONS:Mepoll)
CONFIGURE_ARGS+=	--enable-epoll
.else
CONFIGURE_ARGS+=	--disable-epoll
.endif

###
### Enable IPv6 support
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

###
### Enable remote IPv6 support
###
.if !empty(PKG_OPTIONS:Mremoteinet6)
PKG_SUGGESTED_OPTIONS+=	inet6
CONFIGURE_ARGS+=	--enable-remote-ipv6
.else
CONFIGURE_ARGS+=	--disable-remote-ipv6
.endif

###
### Enable OpenSSL support
###
.if !empty(PKG_OPTIONS:Mssl)
.	include "../../security/openssl/buildlink3.mk"
BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7
CONFIGURE_ARGS+=	--enable-openssl
MODULES+=		m_ssl_openssl.cpp
.endif

###
### Enable GNU TLS support
### Apparently this gives better performance when compared to OpenSSL
###
.if !empty(PKG_OPTIONS:Mgnutls)
.	include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gnutls
MODULES+=		m_ssl_gnutls.cpp
.endif

###
### Compile in support for ziplinks.  This compresses data sent from
### server <-> server with zlib.
###
.if !empty(PKG_OPTIONS:Minspircd-ziplinks)
.	include "../../devel/zlib/buildlink3.mk"
MODULES+=		m_ziplink.cpp
.endif

###
### Perl regex support
###
.if !empty(PKG_OPTIONS:Mpcre)
.	include "../../devel/pcre/buildlink3.mk"
MODULES+=		m_filter_pcre.cpp
.endif

###
### Use SQL for storing user details
###
.if !empty(PKG_OPTIONS:Minspircd-sqlauth)
INSPIRCD_STORAGE_DRIVER?=	mysql
MODULES+=			m_sqlauth.cpp m_sqlutils.cpp
HEADERS+=			m_sqlutils.h
.endif

###
### Use SQL for logging
###
.if !empty(PKG_OPTIONS:Minspircd-sqllog)
INSPIRCD_STORAGE_DRIVER?=	mysql
MODULES+=			m_sqllog.cpp
.endif

###
### Use SQL for storing oper details
###
.if !empty(PKG_OPTIONS:Minspircd-sqloper)
INSPIRCD_STORAGE_DRIVER?=	mysql
MODULES+=			m_sqloper.cpp m_sqlutils.cpp
HEADERS+=			m_sqlutils.h
.endif

###
### Strorage driver magic
###
### This will only be activated if INSPIRCD_STORAGE_DRIVER is set either
### explictly by the user or by selecting one of the options that are
### dependent on an SQL storage driver.
###
.if defined(INSPIRCD_STORAGE_DRIVER)
BUILD_DEFS+=		INSPIRCD_STORAGE_DRIVER
.  if !empty(INSPIRCD_STORAGE_DRIVER:Mmysql)
.	include "../../mk/mysql.buildlink3.mk"
MODULES+=		m_mysql.cpp
HEADERS+=		m_sqlv2.h
.  elif !empty(INSPIRCD_STORAGE_DRIVER:Mpgsql)
.	include "../../mk/pgsql.buildlink3.mk"
MODULES+=		m_pgsql.cpp
HEADERS+=		m_sqlv2.h
.  elif !empty(INSPIRCD_STORAGE_DRIVER:Msqlite3)
.	include "../../databases/sqlite3/buildlink3.mk"
MODULES+=		m_sqlite3.cpp
HEADERS+=		m_sqlv2.h
.  else
PKG_FAIL_REASON+=	"${PKGBASE}: unknown storage driver \\'${INSPIRCD_STORAGE_DRIVER}\\'"
.  endif
.endif
