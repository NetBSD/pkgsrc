# $NetBSD: options.mk,v 1.8 2013/06/15 16:08:09 taca Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.roundcube

PKG_OPTIONS_REQUIRED_GROUPS=	db converters
PKG_OPTIONS_GROUP.db=		mysql pgsql sqlite
PKG_OPTIONS_GROUP.converters=	iconv multibyte

PKG_SUPPORTED_OPTIONS=		ldap sockets gd
PKG_SUGGESTED_OPTIONS=		mysql iconv sockets gd

.include "../../mk/bsd.options.mk"

###
### Use mysql backend.
###
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_mysql-[0-9]*:../../databases/php-pdo_mysql
.endif

###
### Use postgresql backend.
###
.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_pgsql-[0-9]*:../../databases/php-pdo_pgsql
.endif

###
### Use sqlite backend.
###
.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=	${PHP_PKG_PREFIX}-pdo_sqlite-[0-9]*:../../databases/php-pdo_sqlite
.endif

###
### Use iconv.
###
.if !empty(PKG_OPTIONS:Miconv)
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=4.3.1:../../converters/php-iconv
.endif

###
### Use mbstring.
###
.if !empty(PKG_OPTIONS:Mmultibyte)
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=4.3.1:../../converters/php-mbstring
.endif

###
### Use OpenLDAP for storing data.
###
.if !empty(PKG_OPTIONS:Mldap)
DEPENDS+=	${PHP_PKG_PREFIX}-ldap>=4.3.1:../../databases/php-ldap
.endif

###
### Use sockets, required by managesieve and password plugins.
###
.if !empty(PKG_OPTIONS:Msockets)
DEPENDS+=	${PHP_PKG_PREFIX}-sockets>=4.3.1:../../net/php-sockets
.endif

###
### Add support for gd
###
.if !empty(PKG_OPTIONS:Mgd)
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=4.3.1:../../graphics/php-gd
.endif
