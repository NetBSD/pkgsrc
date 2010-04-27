# $NetBSD: options.mk,v 1.3 2010/04/27 14:24:14 matthias Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mapserver
PKG_SUPPORTED_OPTIONS=	fastcgi pgsql mysql x11
PKG_SUGGESTED_OPTIONS=	x11

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

#
# x11 (xpm) support
#
.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libXpm/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-xpm
.endif
