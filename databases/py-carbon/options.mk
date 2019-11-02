# $NetBSD: options.mk,v 1.7 2019/11/02 15:38:09 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-carbon
PKG_SUPPORTED_OPTIONS=	amqp ldap memcached
PKG_SUGGESTED_OPTIONS=	#

.include "../../mk/bsd.options.mk"

###
### AMQP support
###
.if !empty(PKG_OPTIONS:Mamqp)
DEPENDS+=	${PYPKGPREFIX}-txamqp-[0-9]*:../../net/py-txamqp
.endif

###
### LDAP support
###
.if !empty(PKG_OPTIONS:Mldap)
DEPENDS+=	${PYPKGPREFIX}-ldap-[0-9]*:../../databases/py-ldap
PYTHON_VERSIONS_ACCEPTED= 27 # py-ldap
.endif

###
### Memcached support
###
.if !empty(PKG_OPTIONS:Mmemcached)
DEPENDS+=	${PYPKGPREFIX}-memcached-[0-9]*:../../devel/py-memcached
PYTHON_VERSIONS_ACCEPTED= 27 # py-memcached
.endif
