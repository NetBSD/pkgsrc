# $NetBSD: options.mk,v 1.5 2007/10/30 22:52:44 shannonjr Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dbmail
PKG_SUPPORTED_OPTIONS=	sieve
PKG_OPTIONS_REQUIRED_GROUPS=	sql
PKG_OPTIONS_GROUP.sql=	mysql pgsql
PKG_SUGGESTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

###
### MySQL database support
###
.if !empty(PKG_OPTIONS:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
SQLDB=			mysql
.endif

###
### PostgreSQL database support
###
.if !empty(PKG_OPTIONS:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
SQLDB=			pgsql
.endif

###
### libsieve support
###
PLIST_SRC=      ${.CURDIR}/PLIST
.if !empty(PKG_OPTIONS:Msieve)
CONFIGURE_ARGS+=	--with-sieve=${BUILDLINK_PREFIX.libsieve}
PLIST_SRC+=		${.CURDIR}/PLIST.sieve
.include "../../mail/libsieve/buildlink3.mk"
.include "../../mail/gmime/buildlink3.mk"
.endif
