# $NetBSD: options.mk,v 1.4 2010/07/24 09:33:09 obache Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.bogofilter
PKG_OPTIONS_REQUIRED_GROUPS=	database
PKG_OPTIONS_GROUP.database=	bdb qdbm sqlite tokyocabinet
PKG_SUGGESTED_OPTIONS=		bdb
PKG_OPTIONS_LEGACY_OPTS+=	db4:bdb

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbdb)
CONFIGURE_ARGS+=		--with-database=db
BDB_ACCEPTED=			db3 db4 db5
.include "../../mk/bdb.buildlink3.mk"
BUILDLINK_TRANSFORM+=		l:db:${BDB_TYPE}
.endif

PLIST_VARS+=			qdbm
.if !empty(PKG_OPTIONS:Mqdbm)
CONFIGURE_ARGS+=		--with-database=qdbm
PLIST.qdbm=			yes
.include "../../databases/qdbm/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msqlite)
CONFIGURE_ARGS+=		--with-database=sqlite3
.include "../../databases/sqlite3/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mtokyocabinet)
CONFIGURE_ARGS+=		--with-database=tokyocabinet
.include "../../databases/tokyocabinet/buildlink3.mk"
.endif
