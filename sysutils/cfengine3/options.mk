# $NetBSD: options.mk,v 1.2 2015/04/07 08:43:35 fhajny Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.cfengine3
PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=	qdbm tokyocabinet lmdb
PKG_SUPPORTED_OPTIONS=	qdbm tokyocabinet mysql pgsql
PKG_SUGGESTED_OPTIONS=	tokyocabinet

.include "../../mk/bsd.options.mk"

### MySQL support
.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql=${MYSQL_PREFIX}
.include "../../mk/mysql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

### PostgreSQL support
.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-postgresql=${PGSQL_PREFIX}
.include "../../mk/pgsql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-postgresql
.endif

### LMDB *or* QDBM *or* Tokyo Cabinet support
.if !empty(PKG_OPTIONS:Mlmdb)
CONFIGURE_ARGS+=	--with-lmdb=${BUILDLINK_PREFIX.lmdb}
.include "../../databases/lmdb/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mqdbm)
CONFIGURE_ARGS+=	--with-qdbm=${BUILDLINK_PREFIX.qdbm}
.include "../../databases/qdbm/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mtokyocabinet)
CONFIGURE_ARGS+=	--with-tokyocabinet=${BUILDLINK_PREFIX.tokyocabinet}
.include "../../databases/tokyocabinet/buildlink3.mk"
.endif
