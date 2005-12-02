# $NetBSD: options.mk,v 1.1 2005/12/02 17:28:37 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sqlrelay
PKG_SUPPORTED_OPTIONS+= mysql pgsql

# remove legacy handling after 2005Q4
.if defined(SQLRELAY_DATABASES)
.if !empty(SQLRELAY_DATABASES:Mmysql)
PKG_LEGACY_OPTIONS+=	mysql
PKG_OPTIONS_DEPRECATED_WARNINGS+="Deprecated variable SQLRELAY_DATABASES used, use PKG_OPTIONS.sqlrelay+=mysql instead."
.endif
.if !empty(SQLRELAY_DATABASES:Mpostgresql)
PKG_LEGACY_OPTIONS+=	pgsql
PKG_OPTIONS_DEPRECATED_WARNINGS+="Deprecated variable SQLRELAY_DATABASES used, use PKG_OPTIONS.sqlrelay+=pqsql instead."
.endif
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_DIR}
.include "../../mk/mysql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+=	--with-postgresql=${BUILDLINK_DIR}
.include "../../mk/pgsql.buildlink3.mk"
.endif
