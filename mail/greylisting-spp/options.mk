# $NetBSD: options.mk,v 1.1 2018/11/11 01:59:23 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.greylisting-spp
PKG_OPTIONS_OPTIONAL_GROUPS=	db
PKG_OPTIONS_GROUP.db=           db4 sqlite sqlite3
PKG_SUGGESTED_OPTIONS=		sqlite3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdb4)
.  include "../../databases/db4/buildlink3.mk"
BUILD_MAKE_FLAGS+=	DB_IMPL=bdb
.elif !empty(PKG_OPTIONS:Msqlite)
.  include "../../databases/sqlite/buildlink3.mk"
BUILD_MAKE_FLAGS+=	DB_IMPL=sqlite
.elif !empty(PKG_OPTIONS:Msqlite3)
.  include "../../databases/sqlite3/buildlink3.mk"
BUILD_MAKE_FLAGS+=	DB_IMPL=sqlite3
.else
BUILD_MAKE_FLAGS+=	DB_IMPL=file
.endif
