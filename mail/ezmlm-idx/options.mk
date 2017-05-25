# $NetBSD: options.mk,v 1.9 2017/05/25 20:41:27 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ezmlm-idx
PKG_OPTIONS_OPTIONAL_GROUPS=	database
PKG_OPTIONS_GROUP.database=	mysql pgsql sqlite3

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		mysql
.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
DJB_BUILD_TARGETS+=	mysql
PLIST.mysql=		yes
.endif

PLIST_VARS+=		pgsql
.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
DJB_BUILD_TARGETS+=	pgsql
PLIST.pgsql=		yes
.endif

PLIST_VARS+=		sqlite3
.if !empty(PKG_OPTIONS:Msqlite3)
.  include "../../databases/sqlite3/buildlink3.mk"
DJB_BUILD_TARGETS+=	sqlite3
PLIST.sqlite3=		yes
.endif
