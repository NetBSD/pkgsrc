# $NetBSD: options.mk,v 1.1 2020/03/24 13:23:46 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.neko

PKG_SUPPORTED_OPTIONS=	apache mysql pcre sqlite ssl gtk2
PKG_SUGGESTED_OPTIONS=	apache mysql pcre sqlite ssl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	apache
.if !empty(PKG_OPTIONS:Mapache)
CMAKE_ARGS+=	-DWITH_APACHE=ON
.include "../../www/apache24/buildlink3.mk"
PLIST.apache=	yes
.else
CMAKE_ARGS+=	-DWITH_APACHE=OFF
.endif

PLIST_VARS+=	mysql
.if !empty(PKG_OPTIONS:Mmysql)
CMAKE_ARGS+=	-DWITH_MYSQL=ON
.include "../../mk/mysql.buildlink3.mk"
PLIST.mysql=	yes
.else
CMAKE_ARGS+=	-DWITH_MYSQL=OFF
.endif

PLIST_VARS+=	regexp
.if !empty(PKG_OPTIONS:Mpcre)
CMAKE_ARGS+=	-DWITH_REGEXP=ON
.include "../../devel/pcre/buildlink3.mk"
PLIST.regexp=	yes
.else
CMAKE_ARGS+=	-DWITH_REGEXP=OFF
.endif

PLIST_VARS+=	sqlite
.if !empty(PKG_OPTIONS:Msqlite)
CMAKE_ARGS+=	-DWITH_SQLITE=ON
.include "../../databases/sqlite3/buildlink3.mk"
PLIST.sqlite=	yes
.else
CMAKE_ARGS+=	-DWITH_SQLITE=OFF
.endif

PLIST_VARS+=	ssl
.if !empty(PKG_OPTIONS:Mssl)
CMAKE_ARGS+=	-DWITH_SSL=ON
.include "../../security/mbedtls/buildlink3.mk"
PLIST.ssl=	yes
.else
CMAKE_ARGS+=	-DWITH_SSL=OFF
.endif

PLIST_VARS+=	ui
.if !empty(PKG_OPTIONS:Mgtk2)
CMAKE_ARGS+=	-DWITH_UI=ON
.include "../../x11/gtk2/buildlink3.mk"
PLIST.ui=	yes
.else
CMAKE_ARGS+=	-DWITH_UI=OFF
.endif
