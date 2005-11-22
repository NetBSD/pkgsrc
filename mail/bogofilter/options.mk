# $NetBSD: options.mk,v 1.1 2005/11/22 18:15:56 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.bogofilter
PKG_OPTIONS_REQUIRED_GROUPS=	database
PKG_OPTIONS_GROUP.database=	db4 sqlite
PKG_SUGGESTED_OPTIONS=		db4

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdb4)
CONFIGURE_ARGS+=		--with-database=db
.include "../../databases/db4/buildlink3.mk"
BUILDLINK_TRANSFORM+=		l:db:db4
.endif

.if !empty(PKG_OPTIONS:Msqlite)
CONFIGURE_ARGS+=		--with-database=sqlite3
.include "../../databases/sqlite3/buildlink3.mk"
.endif
