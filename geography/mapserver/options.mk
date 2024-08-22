# $NetBSD: options.mk,v 1.8 2024/08/22 12:59:14 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mapserver
PKG_SUPPORTED_OPTIONS=	fastcgi pgsql mysql x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

#
# FastCGI support
#
.if !empty(PKG_OPTIONS:Mfastcgi)
.include "../../www/fcgi/buildlink3.mk"
.else
# Remediate cmake looking out of the bl3 tree.
CMAKE_CONFIGURE_ARGS+=		-DWITH_FCGI=OFF
.endif

#
# PostgreSQL/PostGIS support
#
.if !empty(PKG_OPTIONS:Mpgsql)
# \todo Explain why this is bl3 rather than DEPENDS.  It doesn't make
# sense, given how postgis works.
.include "../../databases/postgresql-postgis2/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=		-D-DWITH_POSTGIS=OFF
.endif

#
# MySQL/MyGIS support
#
.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
# \todo Enable?
.endif

#
# x11 (xpm) support
#
.if !empty(PKG_OPTIONS:Mx11)
.include "../../x11/libXpm/buildlink3.mk"
# \todo Enable/disable?
.endif
