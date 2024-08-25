# $NetBSD: options.mk,v 1.3 2024/08/25 06:18:43 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.etlegacy-server
PKG_SUPPORTED_OPTIONS=		lua sqlite3
PKG_SUGGESTED_OPTIONS=		lua sqlite3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlua)
CMAKE_CONFIGURE_ARGS+=	-DFEATURE_LUA=ON
.include "../../lang/lua54/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DFEATURE_LUA=OFF
.endif

.if !empty(PKG_OPTIONS:Msqlite3)
CMAKE_CONFIGURE_ARGS+=	-DFEATURE_DBMS=ON
.include "../../databases/sqlite3/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DFEATURE_DBMS=OFF
.endif
