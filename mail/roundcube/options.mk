# $NetBSD: options.mk,v 1.12 2015/08/31 15:31:26 taca Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.roundcube

PKG_OPTIONS_REQUIRED_GROUPS=	db converters webserver
PKG_OPTIONS_GROUP.db=		mysql pgsql sqlite
PKG_OPTIONS_GROUP.converters=	iconv multibyte
PKG_OPTIONS_GROUP.webserver=	apache nginx

PKG_SUPPORTED_OPTIONS=		ldap sockets gd
PKG_SUGGESTED_OPTIONS=		mysql iconv sockets gd apache

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
### Use apache web server
###
.if !empty(PKG_OPTIONS:Mapache)
WWW_USER?=              ${APACHE_USER}
WWW_GROUP?=             ${APACHE_GROUP}
BUILD_DEFS+=		APACHE_USER APACHE_GROUP
WWW_CONF_FILE?=		apache.conf
.include "../../mk/apache.mk"
.endif

###
### Use apache web server
###
.if !empty(PKG_OPTIONS:Mnginx)
DEPENDS+=	nginx-[0-9]*:../../www/nginx
WWW_USER?=		nginx
WWW_GROUP?=		nginx
WWW_CONF_FILE?=		nginx.conf
.endif

###
### Use OpenLDAP for storing data.
###
.if !empty(PKG_OPTIONS:Mldap)
DEPENDS+=	${PHP_PKG_PREFIX}-ldap>=4.3.1:../../databases/php-ldap
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_LDAP3-[0-9]*:../../net/pear-Net_LDAP3
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
