# $NetBSD: options.mk,v 1.2 2025/01/23 16:24:02 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.coturn
PKG_SUPPORTED_OPTIONS=	mysql pgsql sqlite redis
PKG_SUGGESTED_OPTIONS=	sqlite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mredis)
.include "../../databases/hiredis/buildlink3.mk"
.else
CONFIGURE_ENV+=		TURN_NO_HIREDIS=1
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
.else
CONFIGURE_ENV+=		TURN_NO_MYSQL=1
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
.else
CONFIGURE_ENV+=		TURN_NO_PQ=1
.endif

.if !empty(PKG_OPTIONS:Msqlite)
.include "../../databases/sqlite3/buildlink3.mk"
.else
CONFIGURE_ENV+=		TURN_NO_SQLITE=1
.endif
