# $NetBSD: options.mk,v 1.1 2023/02/12 18:37:32 otis Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.zabbix60-server
PKG_SUPPORTED_OPTIONS+=		inet6 openipmi libssh libssh2 snmp
PKG_OPTIONS_REQUIRED_GROUPS=	database
PKG_OPTIONS_GROUP.database=	mysql pgsql
PKG_SUGGESTED_OPTIONS+=		openipmi libssh2 pgsql snmp
PKG_OPTIONS_LEGACY_OPTS=	ipmi:openipmi

.if empty(MISSING_FEATURES:Minet6)
PKG_SUGGESTED_OPTIONS+=		inet6
.endif

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		pgsql

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
.endif

.if !empty(PKG_OPTIONS:Mopenipmi)
CONFIGURE_ARGS+=	--with-openipmi=${PREFIX}
.include "../../sysutils/openipmi/buildlink3.mk"
.endif
