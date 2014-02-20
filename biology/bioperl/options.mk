# $NetBSD: options.mk,v 1.1 2014/02/20 14:44:16 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.bioperl
PKG_SUPPORTED_OPTIONS+=	mysql pgsql sqlite

.include "../../mk/bsd.options.mk"

###
### MySQL support
###
.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
DEPENDS+=		p5-DBD-${MYSQL_PKG_PREFIX}-[0-9]*:../../databases/p5-DBD-mysql
.endif

###
### PostgreSQL support
###
.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=		p5-DBD-postgresql-[0-9]*:../../databases/p5-DBD-postgresql
.endif

###
### SQLite support
###
.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=		p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite
.endif
