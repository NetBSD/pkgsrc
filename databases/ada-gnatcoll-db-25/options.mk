# $NetBSD: options.mk,v 1.2 2025/11/03 15:49:39 dkazankov Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gnatcoll-db-25
PKG_SUPPORTED_OPTIONS=		gnatcoll-db2ada gnatcoll-postgres2ada gnatcoll-sqlite2ada gnatcoll-all2ada \
				gnatcoll-gnatinspect gnatcoll-postgres gnatcoll-sql gnatcoll-sqlite gnatcoll-xref
PKG_SUGGESTED_OPTIONS=		gnatcoll-db2ada gnatcoll-postgres2ada gnatcoll-sqlite2ada gnatcoll-all2ada \
				gnatcoll-gnatinspect gnatcoll-postgres gnatcoll-sql gnatcoll-sqlite gnatcoll-xref

.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/bsd.options.mk"

# Build order is important
.if !empty(PKG_OPTIONS:Mgnatcoll-sql)
PKG_BUILD_DIRS+=		sql
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-sqlite)
#.  include "../../databases/sqlite3/buildlink3.mk"
PKG_BUILD_DIRS+=		sqlite
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-postgres)
PKG_BUILD_DIRS+=		postgres
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-xref)
PKG_BUILD_DIRS+=		xref
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-gnatinspect)
PKG_BUILD_DIRS+=		gnatinspect
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-postgres) || !empty(PKG_OPTIONS:Mgnatcoll-xref) || \
    !empty(PKG_OPTIONS:Mgnatcoll-gnatinspect)
.  include "../../devel/ada-gnatcoll-bindings-25/buildlink3.mk"
.  include "../../converters/libiconv/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-db2ada) || !empty(PKG_OPTIONS:Mgnatcoll-postgres2ada) || \
    !empty(PKG_OPTIONS:Mgnatcoll-sqlite2ada) || !empty(PKG_OPTIONS:Mgnatcoll-all2ada)
PKG_BUILD_DIRS+=		gnatcoll_db2ada
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-postgres) || \
    !empty(PKG_OPTIONS:Mgnatcoll-postgres2ada) || !empty(PKG_OPTIONS:Mgnatcoll-all2ada)
.  include "../../mk/pgsql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-db2ada)
DB_BACKENDS+=			db
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-postgres2ada)
DB_BACKENDS+=			postgres
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-sqlite2ada)
DB_BACKENDS+=			sqlite
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-all2ada)
DB_BACKENDS+=			all
.endif
