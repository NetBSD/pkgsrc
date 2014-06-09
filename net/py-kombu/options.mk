# $NetBSD: options.mk,v 1.1 2014/06/09 00:16:23 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-kombu
PKG_SUPPORTED_OPTIONS=	beanstalk couchdb mongo msgpack pyro redis slmq
PKG_SUPPORTED_OPTIONS+=	sqlalchemy sqs yaml zeromq zookeeper
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.include "../../lang/python/pyversion.mk"

.if !empty(PKG_OPTIONS:Mbeanstalk)
DEPENDS+=		${PYPKGPREFIX}-beanstalkc-[0-9]*:../../net/py-beanstalkc
.endif

.if !empty(PKG_OPTIONS:Mcouchdb)
DEPENDS+=		${PYPKGPREFIX}-couchdb-[0-9]*:../../databases/py-couchdb
.endif

# XXX: Not packaged yet. Needs some work.
#.if !empty(PKG_OPTIONS:Mlibrabbitmq)
#DEPENDS+=		${PYPKGPREFIX}-librabbitmq>=1.5.2:../../net/py-librabbitmq
#.endif

.if !empty(PKG_OPTIONS:Mmongo)
DEPENDS+=		${PYPKGPREFIX}-mongo>=2.6.2:../../databases/py-mongo
.endif

.if !empty(PKG_OPTIONS:Mmsgpack)
DEPENDS+=		${PYPKGPREFIX}-msgpack>=0.3.0:../../devel/py-msgpack
.endif

.if !empty(PKG_OPTIONS:Mpyro)
DEPENDS+=		${PYPKGPREFIX}-Pyro4-[0-9]*:../../devel/py-Pyro
.endif

.if !empty(PKG_OPTIONS:Mredis)
DEPENDS+=		redis>2.8.0:../../databases/redis
.endif

.if !empty(PKG_OPTIONS:Mslmq)
DEPENDS+=		${PYPKGPREFIX}-softlayer_messaging>=1.0.3:../../net/py-softlayer_messaging
.endif

.if !empty(PKG_OPTIONS:Msqlalchemy)
DEPENDS+=		${PYPKGPREFIX}-sqlalchemy-[0-9]*:../../databases/py-sqlalchemy
.endif

.if !empty(PKG_OPTIONS:Msqs)
DEPENDS+=		${PYPKGPREFIX}-boto>=2.13.3:../../www/py-boto
.endif

.if !empty(PKG_OPTIONS:Myaml)
DEPENDS+=		${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml
.endif

.if !empty(PKG_OPTIONS:Mzeromq)
DEPENDS+=		${PYPKGPREFIX}-zmq>=13.1.0:../../net/py-zmq
.endif

.if !empty(PKG_OPTIONS:Mzookeeper)
DEPENDS+=		${PYPKGPREFIX}-kazoo>=1.3.1:../../sysutils/py-kazoo
.endif
