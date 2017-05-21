# $NetBSD: options.mk,v 1.1 2017/05/21 17:30:03 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.zabbix
PKG_SUPPORTED_OPTIONS+=		inet6 libssh2 snmp
PKG_OPTIONS_OPTIONAL_GROUPS=	database
PKG_OPTIONS_GROUP.database=	mysql pgsql sqlite3
PKG_SUGGESTED_OPTIONS+=		libssh2 snmp pgsql

.if empty(MISSING_FEATURES:Minet6)
PKG_SUGGESTED_OPTIONS+=		inet6
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mlibssh2)
CONFIGURE_ARGS+=	--with-ssh2=${BUILDLINK_PREFIX.libssh2}
.include "../../security/libssh2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql
.include "../../mk/mysql.buildlink3.mk"
ZABBIX_DB_TYPE=		mysql
.endif

.if !empty(PKG_OPTIONS:Msnmp)
CONFIGURE_ARGS+=	--with-net-snmp
.include "../../net/net-snmp/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-postgresql
.include "../../mk/pgsql.buildlink3.mk"
ZABBIX_DB_TYPE=		postgresql
.endif

.if !empty(PKG_OPTIONS:Msqlite3)
CONFIGURE_ARGS+=	--with-sqlite3=${BUILDLINK_PREFIX.sqlite3}
.include "../../databases/sqlite3/buildlink3.mk"
ZABBIX_DB_TYPE=		sqlite3
.endif
