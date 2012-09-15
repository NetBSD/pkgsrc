# $NetBSD: options.mk,v 1.7 2012/09/15 13:24:13 obache Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.roundcube

PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		mysql pgsql

PKG_SUPPORTED_OPTIONS=		iconv ldap multibyte mcrypt sockets gd
# Following the recommendations in INSTALL the iconv, multibyte, gd and
# mcrypt PHP extensions are all 'recommended' requirements
PKG_SUGGESTED_OPTIONS=		mysql iconv multibyte mcrypt sockets gd

.if ${PKG_PHP_VERSION} == "53"
PKG_OPTIONS_GROUP.db+=		sqlite
.endif

.include "../../mk/bsd.options.mk"

###
### Use mysql backend
###
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=4.3.1:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-pear-MDB2_Driver_mysql>1.5:../../databases/pear-MDB2_Driver_mysql
.endif

###
### Use postgresql backend
###
.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=4.3.1:../../databases/php-pgsql
DEPENDS+=	${PHP_PKG_PREFIX}-pear-MDB2_Driver_pgsql>=1.5:../../databases/pear-MDB2_Driver_pgsql
.endif

###
### Use sqlite backend
###
.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=	${PHP_PKG_PREFIX}-sqlite-[0-9]*:../../databases/php-sqlite
DEPENDS+=	${PHP_PKG_PREFIX}-pear-MDB2_Driver_sqlite>1.5:../../databases/pear-MDB2_Driver_sqlite
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
DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=4.3.1:../../converters/php-mbstring
.endif

###
### Use mcrypt
###
.if !empty(PKG_OPTIONS:Mmcrypt)
DEPENDS+=	${PHP_PKG_PREFIX}-mcrypt>=4.3.1:../../security/php-mcrypt
.endif

###
### Use sockets
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
