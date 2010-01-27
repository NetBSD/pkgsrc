# $NetBSD: options.mk,v 1.2 2010/01/27 08:12:19 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mapserver
PKG_SUPPORTED_OPTIONS=	fastcgi pgsql mysql
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

#
# FastCGI support
#
.if !empty(PKG_OPTIONS:Mfastcgi)
.include "../../www/fcgi/buildlink3.mk"
CONFIGURE_ARGS+=	--with-fastcgi
.endif

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
