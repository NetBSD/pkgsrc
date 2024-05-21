# $NetBSD: options.mk,v 1.7 2024/05/21 13:36:10 gdt Exp $

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
.else
# The builds says:
#   -- Could NOT find MySQL (missing: MYSQL_LIBRARY MYSQL_INCLUDE_DIR)
# but cmake -L does not show the option to turn it off.
.endif

# For now, there is no ODBC option, and hence only the "no ODBC" case.
CMAKE_CONFIGURE_ARGS+=	-DGDAL_USE_ODBC=OFF
