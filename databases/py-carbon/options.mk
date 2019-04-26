# $NetBSD: options.mk,v 1.5 2019/04/26 13:13:46 maya Exp $

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
PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # py-ldap
.endif

###
### Memcached support
###
.if !empty(PKG_OPTIONS:Mmemcached)
DEPENDS+=	${PYPKGPREFIX}-memcached-[0-9]*:../../devel/py-memcached
PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # py-memcached
.endif
