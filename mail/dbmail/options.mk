# $NetBSD: options.mk,v 1.2 2005/05/31 10:01:37 dillo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dbmail
PKG_SUPPORTED_OPTIONS=	mysql pgsql
PKG_SUGGESTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

###
### We can't compile support for both MySQL and PostgreSQL.
###
.if !empty(PKG_OPTIONS:Mmysql) && !empty(PKG_OPTIONS:Mpgsql)
PKG_FAIL_REASON+=       "MySQL and PostgreSQL cannot both be compiled in." \
			"Please change ${PKG_OPTIONS_VAR} to one or the other."
.endif

###
### MySQL database support
###
.if !empty(PKG_OPTIONS:Mmysql)
.include "../../databases/mysql4-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql
SQLDB=			mysql
.endif

###
### PostgreSQL database support
###
.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	postgresql74-client-[0-9]*:../../databases/postgresql74-client
.include "../../databases/postgresql74-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql
SQLDB=			pgsql
.endif
