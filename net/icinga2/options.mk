# $NetBSD: options.mk,v 1.2 2021/01/15 12:05:06 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.icinga2
PKG_SUPPORTED_OPTIONS=	debug
PKG_SUPPORTED_OPTIONS+=	mysql pgsql
PKG_SUPPORTED_OPTIONS+=	icingadb
PKG_SUPPORTED_OPTIONS+=	icinga2-checker icinga2-compat
PKG_SUPPORTED_OPTIONS+=	icinga2-livestatus icinga2-notification icinga2-perfdata
PKG_SUGGESTED_OPTIONS=	icinga2-checker icinga2-compat
PKG_SUGGESTED_OPTIONS+=	icinga2-livestatus icinga2-notification icinga2-perfdata

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	mysql pgsql

.if !empty(PKG_OPTIONS:Mmysql)
PLIST.mysql=	yes
CMAKE_ARGS+=	-DICINGA2_WITH_MYSQL=ON
.include "../../mk/mysql.buildlink3.mk"
.else
CMAKE_ARGS+=	-DICINGA2_WITH_MYSQL=OFF
.endif
.if !empty(PKG_OPTIONS:Mpgsql)
PLIST.pgsql=	yes
CMAKE_ARGS+=	-DICINGA2_WITH_PGSQL=ON
.include "../../mk/pgsql.buildlink3.mk"
.else
CMAKE_ARGS+=	-DICINGA2_WITH_PGSQL=OFF
.endif

PLIST_VARS+=	icingadb
.if !empty(PKG_OPTIONS:Micingadb)
CMAKE_ARGS+=	-DICINGA2_WITH_ICINGADB=ON
PLIST.icingadb=	yes
.else
CMAKE_ARGS+=	-DICINGA2_WITH_ICINGADB=OFF
.endif

.for option in checker compat livestatus notification perfdata
PLIST_VARS+=		${option}
.  if !empty(PKG_OPTIONS:Micinga2-${option})
CMAKE_ARGS+=		-DICINGA2_WITH_${option:tu}=ON
PLIST.${option}=	yes
.  else
CMAKE_ARGS+=		-DICINGA2_WITH_${option:tu}=OFF
.  endif
.endfor
