# $NetBSD: options.mk,v 1.21 2014/10/12 00:08:26 gdt Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.bacula
PKG_SUPPORTED_OPTIONS=		ssl
PKG_OPTIONS_REQUIRED_GROUPS=	database
PKG_OPTIONS_GROUP.database=	catalog-sqlite3 catalog-pgsql catalog-mysql
PKG_SUGGESTED_OPTIONS=		ssl catalog-sqlite3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcatalog-sqlite3)
.  include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sqlite3=${BUILDLINK_PREFIX.sqlite3}
BACULA_DB=		sqlite3
.elif !empty(PKG_OPTIONS:Mcatalog-pgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-postgresql=${PGSQL_PREFIX}
BACULA_DB=		postgresql
.elif !empty(PKG_OPTIONS:Mcatalog-mysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql=${PREFIX}
BACULA_DB=		mysql
.endif

.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
.else
CONFIGURE_ARGS+=	--without-openssl
.endif
