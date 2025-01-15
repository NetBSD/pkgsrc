# $NetBSD: options.mk,v 1.1 2025/01/15 14:13:39 manu Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.coturn
PKG_SUPPORTED_OPTIONS=		hiredis mysql pgsql sqlite redis

PKG_SUGGESTED_OPTIONS=		sqlite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mhiredis)
.include "../../databases/hiredis/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msqlite)
.include "../../databases/sqlite3/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mredis)
DEPENDS+=	redis-[0-9]*:../../databases/redis
.endif
