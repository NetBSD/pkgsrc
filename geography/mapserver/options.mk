# $NetBSD: options.mk,v 1.1 2010/01/26 09:01:24 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mapserver
PKG_SUPPORTED_OPTIONS=	pgsql mysql
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

#
# PostgreSQL/PostGIS support
#
.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../databases/postgresql-postgis/buildlink3.mk"
CONFIGURE_ARGS+=	--with-postgis
.endif

#
# MySQL/MyGIS support
#
.if !empty(PKG_OPTIONS:Mmysql)
.include "../../databases/mysql5-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-mygis
.endif
