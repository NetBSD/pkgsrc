# $NetBSD: options.mk,v 1.8 2022/05/11 15:12:25 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-carbon
PKG_SUPPORTED_OPTIONS=	amqp memcached
PKG_SUGGESTED_OPTIONS=	#

.include "../../mk/bsd.options.mk"

###
### AMQP support
###
.if !empty(PKG_OPTIONS:Mamqp)
DEPENDS+=	${PYPKGPREFIX}-txamqp-[0-9]*:../../net/py-txamqp
.endif

###
### Memcached support
###
.if !empty(PKG_OPTIONS:Mmemcached)
DEPENDS+=	${PYPKGPREFIX}-memcached-[0-9]*:../../devel/py-memcached
PYTHON_VERSIONS_ACCEPTED= 27 # py-memcached
.endif
