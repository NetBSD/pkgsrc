# $NetBSD: options.mk,v 1.5 2005/11/22 19:33:06 tv Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.bacula
PKG_OPTIONS_REQUIRED_GROUPS=	database
PKG_OPTIONS_GROUP.database=	catalog-sqlite catalog-pgsql catalog-mysql
PKG_SUGGESTED_OPTIONS=		catalog-sqlite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcatalog-sqlite)
.  include "../../databases/sqlite/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sqlite=${BUILDLINK_PREFIX.sqlite}
BACULA_DB=		sqlite
.elif !empty(PKG_OPTIONS:Mcatalog-pgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-postgresql=${PGSQL_PREFIX}
BACULA_DB=		postgresql
.elif !empty(PKG_OPTIONS:Mcatalog-mysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql=${PREFIX}
BACULA_DB=		mysql
.endif
