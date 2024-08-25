# $NetBSD: options.mk,v 1.4 2024/08/25 06:18:31 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.soci
PKG_SUPPORTED_OPTIONS=	boost mysql pgsql sqlite
PKG_SUGGESTED_OPTIONS=	pgsql

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	mysql pgsql sqlite

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DWITH_MYSQL=ON
PLIST.mysql=	yes
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_MYSQL=OFF
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DWITH_POSTGRESQL=ON
PLIST.pgsql=	yes
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_POSTGRESQL=OFF
.endif

.if !empty(PKG_OPTIONS:Msqlite)
.include "../../databases/sqlite3/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DWITH_SQLITE3=ON
PLIST.sqlite=	yes
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_SQLITE3=OFF
.endif

.if !empty(PKG_OPTIONS:Mboost)
.include "../../devel/boost-libs/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=    -DWITH_BOOST=ON
.else
CMAKE_CONFIGURE_ARGS+=    -DWITH_BOOST=OFF
.endif
