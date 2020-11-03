# $NetBSD: options.mk,v 1.1 2020/11/03 22:48:55 otis Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.zabbix50-frontend
PKG_OPTIONS_OPTIONAL_GROUPS=	database
PKG_OPTIONS_GROUP.database=	mysql pgsql
PKG_SUGGESTED_OPTIONS+=		pgsql

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		pgsql
PLIST_VARS+=		mysql

.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql
.include "../../mk/mysql.buildlink3.mk"
ZABBIX_DB_TYPE=		mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-postgresql
.include "../../mk/pgsql.buildlink3.mk"
ZABBIX_DB_TYPE=		postgresql
PLIST.pgsql=		yes
.endif
