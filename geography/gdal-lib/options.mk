# $NetBSD: options.mk,v 1.2 2010/08/27 11:14:23 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gdal-lib
PKG_SUPPORTED_OPTIONS=	pgsql mysql sqlite
PKG_SUGGESTED_OPTIONS=	pgsql

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
