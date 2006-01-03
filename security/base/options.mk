# $NetBSD: options.mk,v 1.1.1.1 2006/01/03 21:09:44 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.base

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql pgsql

PKG_SUGGESTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

###
### Use PostgreSQL for storing BASE raw data
###
.if !empty(PKG_OPTIONS:Mpgsql)
.	include "../../mk/pgsql.buildlink3.mk"
DBTYPE=		postgres
.elif !empty(PKG_OPTIONS:Mmysql)
###
### Use MySQL for storing BASE raw data
###
.	include "../../mk/mysql.buildlink3.mk"
DBTYPE=		mysql
.endif
