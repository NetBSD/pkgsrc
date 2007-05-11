# $NetBSD: options.mk,v 1.2 2007/05/11 11:51:05 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.roundcube

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql pgsql sqlite

PKG_SUPPORTED_OPTIONS=	iconv ldap multibyte
PKG_SUGGESTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

.include "../../lang/php/phpversion.mk"

###
### Use mysql backend
###
.if !empty(PKG_OPTIONS:Mmysql)
.	include "../../mk/mysql.buildlink3.mk"
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=4.3.1:../../databases/php-mysql
.endif

###
### Use postgresql backend
###
.if !empty(PKG_OPTIONS:Mpgsql)
.	include "../../mk/pgsql.buildlink3.mk"
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=4.3.1:../../databases/php-pgsql
.endif

###
### Use sqlite backend
###
.if !empty(PKG_OPTIONS:Msqlite)
PHP_VERSIONS_ACCEPTED=	4
.	include "../../databases/sqlite/buildlink3.mk"
DEPENDS+=	${PHP_PKG_PREFIX}-sqlite-[0-9]*:../../databases/php-sqlite
.endif

###
### Use iconv
###
.if !empty(PKG_OPTIONS:Miconv)
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=4.3.1:../../converters/php-iconv
.endif

###
### Use OpenLDAP for storing data
###
.if !empty(PKG_OPTIONS:Mldap)
DEPENDS+=	${PHP_PKG_PREFIX}-ldap>=4.3.1:../../databases/php-ldap
.endif

###
### Use mbstring
###
.if !empty(PKG_OPTIONS:Mmultibyte)
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=4.3.1:../../misc/php-mbstring
.endif
