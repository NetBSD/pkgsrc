# $NetBSD: options.mk,v 1.3 2008/04/12 22:43:03 jlam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.bogofilter
PKG_OPTIONS_REQUIRED_GROUPS=	database
PKG_OPTIONS_GROUP.database=	db4 qdbm sqlite
PKG_SUGGESTED_OPTIONS=		db4

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdb4)
CONFIGURE_ARGS+=		--with-database=db
.include "../../databases/db4/buildlink3.mk"
BUILDLINK_TRANSFORM+=		l:db:db4
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
