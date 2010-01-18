# $NetBSD: options.mk,v 1.1 2010/01/18 09:36:09 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gdal-lib
PKG_SUPPORTED_OPTIONS=	pgsql mysql
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
