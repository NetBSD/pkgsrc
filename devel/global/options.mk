# $NetBSD: options.mk,v 1.1 2015/04/02 22:39:45 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.global
PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=	bdb sqlite3
PKG_SUGGESTED_OPTIONS=	sqlite3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbdb)
.include "../../mk/bdb.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msqlite3)
CONFIGURE_ARGS+=	 --with-sqlite3
.include "../../databases/sqlite3/buildlink3.mk"
.endif
