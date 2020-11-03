# $NetBSD: options.mk,v 1.1 2020/11/03 22:45:38 otis Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.zabbix50-proxy
PKG_SUPPORTED_OPTIONS+=		inet6 ipmi libssh libssh2 snmp
PKG_OPTIONS_OPTIONAL_GROUPS=	database
PKG_OPTIONS_GROUP.database=	mysql pgsql sqlite3
PKG_SUGGESTED_OPTIONS+=		libssh2 pgsql snmp

.if empty(MISSING_FEATURES:Minet6)
PKG_SUGGESTED_OPTIONS+=		inet6
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		pgsql
PLIST_VARS+=		sqldb

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mlibssh)
CONFIGURE_ARGS+=	--with-ssh=${BUILDLINK_PREFIX.libssh}
.include "../../security/libssh/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibssh2)
CONFIGURE_ARGS+=	--with-ssh2=${BUILDLINK_PREFIX.libssh2}
.include "../../security/libssh2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql
.include "../../mk/mysql.buildlink3.mk"
ZABBIX_DB_TYPE=		mysql
PLIST.sqldb=		yes
.endif

.if !empty(PKG_OPTIONS:Msnmp)
CONFIGURE_ARGS+=	--with-net-snmp
.include "../../net/net-snmp/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-postgresql
.include "../../mk/pgsql.buildlink3.mk"
ZABBIX_DB_TYPE=		postgresql
PLIST.pgsql=		yes
PLIST.sqldb=		yes
.endif

.if !empty(PKG_OPTIONS:Msqlite3)
CONFIGURE_ARGS+=	--with-sqlite3=${BUILDLINK_PREFIX.sqlite3}
.include "../../databases/sqlite3/buildlink3.mk"
ZABBIX_DB_TYPE=		sqlite3
.endif

.if !empty(PKG_OPTIONS:Mipmi)
CONFIGURE_ARGS+=	--with-openipmi=${PREFIX}
.include "../../sysutils/openipmi/buildlink3.mk"
.endif
