# $NetBSD: options.mk,v 1.5 2019/06/21 11:25:00 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-kombu
PKG_SUPPORTED_OPTIONS=	beanstalk couchdb mongo msgpack pyro redis slmq
PKG_SUPPORTED_OPTIONS+=	sqlalchemy sqs zeromq zookeeper
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.include "../../lang/python/pyversion.mk"

.if !empty(PKG_OPTIONS:Mbeanstalk)
DEPENDS+=	${PYPKGPREFIX}-beanstalkc-[0-9]*:../../net/py-beanstalkc
.endif

.if !empty(PKG_OPTIONS:Mcouchdb)
DEPENDS+=	${PYPKGPREFIX}-couchdb-[0-9]*:../../databases/py-couchdb
.endif

# XXX: Not packaged yet. Needs some work.
#.if !empty(PKG_OPTIONS:Mlibrabbitmq)
#DEPENDS+=	${PYPKGPREFIX}-librabbitmq>=1.5.2:../../net/py-librabbitmq
#.endif

.if !empty(PKG_OPTIONS:Mmongo)
DEPENDS+=	${PYPKGPREFIX}-mongo>=2.6.2:../../databases/py-mongo
.endif

.if !empty(PKG_OPTIONS:Mmsgpack)
DEPENDS+=	${PYPKGPREFIX}-msgpack>=0.3.0:../../devel/py-msgpack
.endif

.if !empty(PKG_OPTIONS:Mpyro)
DEPENDS+=	${PYPKGPREFIX}-Pyro4-[0-9]*:../../devel/py-Pyro
.endif

.if !empty(PKG_OPTIONS:Mredis)
DEPENDS+=	${PYPKGPREFIX}-redis>=3.2.0:../../databases/py-redis
.endif

.if !empty(PKG_OPTIONS:Mslmq)
DEPENDS+=	${PYPKGPREFIX}-softlayer_messaging>=1.0.3:../../net/py-softlayer_messaging
.endif

.if !empty(PKG_OPTIONS:Msqlalchemy)
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-[0-9]*:../../databases/py-sqlalchemy
.endif

.if !empty(PKG_OPTIONS:Msqs)
DEPENDS+=	${PYPKGPREFIX}-boto3>=1.4.4:../../net/py-boto3
DEPENDS+=	${PYPKGPREFIX}-curl-[0-9]*:../../www/py-curl
.endif

.if !empty(PKG_OPTIONS:Mzeromq)
DEPENDS+=	${PYPKGPREFIX}-zmq>=13.1.0:../../net/py-zmq
.endif

.if !empty(PKG_OPTIONS:Mzookeeper)
DEPENDS+=	${PYPKGPREFIX}-kazoo>=1.3.1:../../sysutils/py-kazoo
.endif
