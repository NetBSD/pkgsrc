# $NetBSD: options.mk,v 1.3 2006/01/10 12:39:04 ghen Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dbmail
PKG_OPTIONS_REQUIRED_GROUPS=	sql
PKG_OPTIONS_GROUP.sql=	mysql pgsql
PKG_SUGGESTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

###
### MySQL database support
###
.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql
SQLDB=			mysql
.endif

###
### PostgreSQL database support
###
.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql
SQLDB=			pgsql
.endif
