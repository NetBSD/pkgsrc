# $NetBSD: options.mk,v 1.5 2012/12/14 19:36:37 drochner Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.sqlite3
PKG_SUPPORTED_OPTIONS=		fts icu rtree
PKG_SUGGESTED_OPTIONS=		fts # enabled in NetBSD builtin version

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfts)
CFLAGS+=	-DSQLITE_ENABLE_FTS4=1 -DSQLITE_ENABLE_FTS3_PARENTHESIS=1
.endif

.if !empty(PKG_OPTIONS:Micu)
CFLAGS+=	-DSQLITE_ENABLE_ICU=1
LDFLAGS+=	-licui18n -licuuc -licudata
.include "../../textproc/icu/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mrtree)
CFLAGS+=	-DSQLITE_ENABLE_RTREE=1
.endif
