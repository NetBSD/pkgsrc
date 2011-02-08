# $NetBSD: options.mk,v 1.1.1.1 2011/02/08 18:32:23 drochner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gps
PKG_SUPPORTED_OPTIONS=	sqlite pgsql
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"


######################
##  SQLITE SUPPORT  ##
######################

.if !empty(PKG_OPTIONS:Msqlite)
CONFIGURE_ARGS+= --with-sqlite=${PREFIX}
.include "../../databases/sqlite/buildlink3.mk"
.endif


##########################
##  POSTGRESQL SUPPORT  ##
##########################

.if !empty(PKG_OPTIONS:Mpgsql)
CONFIGURE_ARGS+= --with-postgresql=${PREFIX}
.include "../../databases/postgresql90-client/buildlink3.mk"
.endif
