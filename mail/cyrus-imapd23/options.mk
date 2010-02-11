# $NetBSD: options.mk,v 1.1.1.1 2010/02/11 08:27:09 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.cyrus-imapd
PKG_SUPPORTED_OPTIONS=	gssapi kerberos kerberos4 ldap snmp
PKG_SUPPORTED_OPTIONS+=	bdb mysql pgsql sqlite
PKG_SUGGESTED_OPTIONS=	bdb

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	ldap

.if !empty(PKG_OPTIONS:Mkerberos)
.  if empty(PKG_OPTIONS:Mgssapi)
PKG_OPTIONS+=	gssapi
.  endif
.endif

.if !empty(PKG_OPTIONS:Mkerberos4)
.  if exists(/usr/include/kerberosIV/krb.h)
PKG_USE_KERBEROS=	yes
CONFIGURE_ARGS+=	--with-krb=/usr
.  endif
.elif !empty(PKG_OPTIONS:Mgssapi)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gssapi=${KRB5BASE}
CONFIGURE_ARGS+=	--with-gss_impl=${GSSIMPL.${KRB5_TYPE}}
GSSIMPL.heimdal=	heimdal
GSSIMPL.mit-krb5=	mit
CONFIGURE_ENV+=		COMPILE_ET=${KRB5BASE}/bin/compile_et
COMERRBASE=		${KRB5BASE}
.else
CONFIGURE_ARGS+=	--without-krb
CONFIGURE_ARGS+=	--disable-gssapi
.endif

.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap-client}
PLIST.ldap=		yes
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if !empty(PKG_OPTIONS:Msnmp)
.  include "../../net/net-snmp/buildlink3.mk"
CONFIGURE_ARGS+=	--with-snmp=${BUILDLINK_PREFIX.net-snmp}
USE_TOOLS+=		perl:run
.else
CONFIGURE_ARGS+=	--without-snmp
.endif

.if !empty(PKG_OPTIONS:Mzephyr)
.  include "../../chat/zephyr/buildlink3.mk"
CONFIGURE_ARGS+=	--with-zephyr=${BUILDLINK_PREFIX.zephyr}
.else
CONFIGURE_ARGS+=	--without-zephyr
.endif

.if !empty(PKG_OPTIONS:Mbdb)
BDB_ACCEPTED=		db4 db3
.  include "../../mk/bdb.buildlink3.mk"
CONFIGURE_ARGS+=	--with-bdb=${BDB_TYPE}
CONFIGURE_ARGS+=	--with-bdb-incdir=${BDBBASE}/include/${BDB_TYPE}
CONFIGURE_ARGS+=	--with-bdb-libdir=${BDBBASE}/lib
.else
CONFIGURE_ARGS+=	--without-bdb
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql=${PGSQL_PREFIX}
.else
CONFIGURE_ARGS+=	--without-pgsql
.endif

.if !empty(PKG_OPTIONS:Msqlite)
.  include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sqlite=${BUILDLINK_PREFIX.sqlite3}
.else
CONFIGURE_ARGS+=	--without-sqlite
.endif
