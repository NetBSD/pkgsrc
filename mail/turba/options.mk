# $NetBSD: options.mk,v 1.6 2019/11/02 16:25:29 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.turba
PKG_SUPPORTED_OPTIONS=	ldap mysql
PKG_SUGGESTED_OPTIONS=	ldap

.include "../../mk/bsd.options.mk"

###
### Use OpenLDAP for storing data
###
.if !empty(PKG_OPTIONS:Mldap)
DEPENDS+=	${PHP_PKG_PREFIX}-ldap>=4.3.3:../../databases/php-ldap
.endif

###
### Use MySQL for storing data
###
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=		${PHP_PKG_PREFIX}-mysql>=4.3.3:../../databases/php-mysql
PHP_VERSIONS_ACCEPTED=	56
.endif
