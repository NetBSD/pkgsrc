# $NetBSD: options.mk,v 1.11 2024/11/11 13:03:16 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mapserver
PKG_SUPPORTED_OPTIONS=	fastcgi pgsql mysql
PKG_SUGGESTED_OPTIONS=	fastcgi pgsql

.include "../../mk/bsd.options.mk"

#
# FastCGI support
#
.if !empty(PKG_OPTIONS:Mfastcgi)
.include "../../www/fcgi/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=		-DWITH_FCGI=ON
.else
# Remediate cmake looking out of the bl3 tree.
CMAKE_CONFIGURE_ARGS+=		-DWITH_FCGI=OFF
.endif

#
# PostgreSQL/PostGIS support
#
.if !empty(PKG_OPTIONS:Mpgsql)
# The server needs postgis, but mapserv needs only postgresql client
# libraries.
.include "../../mk/pgsql.buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=		-DWITH_POSTGIS=ON
.else
CMAKE_CONFIGURE_ARGS+=		-DWITH_POSTGIS=OFF
.endif

#
# MySQL/MyGIS support
#
.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=		-DWITH_MYSQL=ON
.else
CMAKE_CONFIGURE_ARGS+=		-DWITH_MYSQL=OFF
.endif
