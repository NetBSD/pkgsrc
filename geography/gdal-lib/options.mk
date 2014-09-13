# $NetBSD: options.mk,v 1.3 2014/09/13 00:57:00 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gdal-lib

# Note that these are not a mutually-exclusive group.
PKG_SUPPORTED_OPTIONS=	pgsql mysql sqlite
# By default, omit database support, because there isn't an
# articulated use case and dependency management becomes very painful.
# For example, depending on pgsql fixes a version, but doesn't put it
# in the name, and then building postgis fails for all but that one
# chosen version.
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpgsql)
. include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pg
.else
CONFIGURE_ARGS+=	--without-pg
.endif

.if !empty(PKG_OPTIONS:Mmysql)
. include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if !empty(PKG_OPTIONS:Msqlite)
. include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sqlite3=${BUILDLINK_PREFIX.sqlite3}
.else
CONFIGURE_ARGS+=	--without-sqlite3
.endif
