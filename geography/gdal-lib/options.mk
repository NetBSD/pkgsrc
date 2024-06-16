# $NetBSD: options.mk,v 1.8 2024/06/16 12:23:12 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gdal-lib

# Note that these are not a mutually-exclusive group.
PKG_SUPPORTED_OPTIONS=	pgsql mysql
# By default, omit database support, because there isn't an
# articulated use case and dependency management becomes very painful.
# For example, depending on pgsql fixes a version, but doesn't put it
# in the name, and then building postgis fails for all but that one
# chosen version.
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_POSTGRESQL=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_POSTGRESQL=OFF
.endif

# \todo Fix/test MYSQL
.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_MYSQL=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_MYSQL=OFF
.endif

# For now, there is no ODBC option, and hence only the "no ODBC" case.
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_ODBC=OFF
