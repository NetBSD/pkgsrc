# $NetBSD: options.mk,v 1.1 2015/08/30 17:41:51 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libzdb
PKG_SUPPORTED_OPTIONS=		ssl libzdb-sqliteunlock
PKG_SUGGESTED_OPTIONS=		ssl mysql pgsql sqlite
PKG_OPTIONS_NONEMPTY_SETS=	database
PKG_OPTIONS_SET.database=	mysql pgsql sqlite

.include "../../mk/bsd.options.mk"

###
### Support using a MySQL database server
###
.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}/bin/mysql_config
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

###
### Support using a PostgreSQL database server
###
.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-postgresql=${BUILDLINK_PREFIX.postgresql-lib}
.else
CONFIGURE_ARGS+=	--without-postgresql
.endif

###
### Support using a SQLite database
###
.if !empty(PKG_OPTIONS:Msqlite)
.  include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sqlite=${BUILDLINK_PREFIX.sqlite3}
.  if !empty(PKG_OPTIONS:Mlibzdb-sqliteunlock)
CONFIGURE_ARGS+=	--enable-sqliteunlock
.  endif
.else
CONFIGURE_ARGS+=	--without-sqlite
.endif

###
### Support OpenSSL cryptographic library
###
.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--enable-openssl
.  include "../../security/openssl/buildlink3.mk"
.endif
