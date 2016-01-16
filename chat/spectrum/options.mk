# $NetBSD: options.mk,v 1.2 2016/01/16 12:18:42 ryoon Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.spectrum
PKG_OPTIONS_REQUIRED_GROUPS=	storage
PKG_OPTIONS_OPTIONAL_GROUPS=	debug
PKG_OPTIONS_GROUP.storage=	mysql sqlite
PKG_OPTIONS_GROUP.debug=	debug cppunit

PKG_SUGGESTED_OPTIONS=		sqlite

.include "../../mk/bsd.options.mk"

PLIST_VARS+=			sqlite mysql
CMAKE_ARGS+=	-DPOCO_ODBC=OFF

.if !empty(PKG_OPTIONS:Msqlite)
. include "../../databases/poco-data-sqlite/buildlink3.mk"
CMAKE_ARGS+=	-DPOCO_MYSQL=OFF
PLIST.sqlite=	yes
.endif

.if !empty(PKG_OPTIONS:Mmysql)
. include "../../databases/poco-data-mysql/buildlink3.mk"
CMAKE_ARGS+=	-DPOCO_SQLITE=OFF
PLIST.mysql=	yes
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE=Debug
.endif

.if !empty(PKG_OPTIONS:Mcppunit)
. include "../../devel/cppunit/buildlink3.mk"
.endif
