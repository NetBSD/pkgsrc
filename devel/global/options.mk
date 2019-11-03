# $NetBSD: options.mk,v 1.3 2019/11/03 10:39:12 rillig Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.global
PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		bdb sqlite3
PKG_SUGGESTED_OPTIONS=		sqlite3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbdb)
.include "../../mk/bdb.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msqlite3)
CONFIGURE_ARGS+=	--with-sqlite3
LDFLAGS+=		-L${BUILDLINK_PREFIX.sqlite3}/lib \
			${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib
.include "../../databases/sqlite3/buildlink3.mk"
.endif
