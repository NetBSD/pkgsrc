# $NetBSD: options.mk,v 1.7 2022/07/11 13:34:53 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-sqlalchemy-utils
PKG_SUPPORTED_OPTIONS=	arrow babel color furl intervals ipaddress json password
PKG_SUPPORTED_OPTIONS+=	phone tests timezone
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Marrow)
DEPENDS+=	${PYPKGPREFIX}-arrow>=0.3.4:../../time/py-arrow
PYTHON_VERSIONS_INCOMPATIBLE=	27
.endif

.if !empty(PKG_OPTIONS:Mbabel)
DEPENDS+=	${PYPKGPREFIX}-babel>=1.3:../../devel/py-babel
.endif

.if !empty(PKG_OPTIONS:Mcolor)
DEPENDS+=	${PYPKGPREFIX}-colour>=0.0.4:../../textproc/py-colour
.endif

.if !empty(PKG_OPTIONS:Mfurl)
DEPENDS+=	${PYPKGPREFIX}-furl>=0.3.5:../../www/py-furl
.endif

.if !empty(PKG_OPTIONS:Mintervals)
DEPENDS+=	${PYPKGPREFIX}-intervals>=0.2.4:../../math/py-intervals
.endif

.if !empty(PKG_OPTIONS:Mipaddress)
DEPENDS+=	${PYPKGPREFIX}-ipaddr-[0-9]*:../../devel/py-ipaddr
.endif

.if !empty(PKG_OPTIONS:Mjson)
DEPENDS+=	${PYPKGPREFIX}-anyjson>=0.3.3:../../textproc/py-anyjson
.endif

.if !empty(PKG_OPTIONS:Mpassword)
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.6<2.0:../../security/py-passlib
.endif

.if !empty(PKG_OPTIONS:Mphone)
DEPENDS+=	${PYPKGPREFIX}-phonenumbers>=5.9.2:../../textproc/py-phonenumbers
.endif

.if !empty(PKG_OPTIONS:Mtests)
PYTHON_VERSIONED_DEPENDENCIES=	pygments test
.include "../../lang/python/versioned_dependencies.mk"
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.10:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-flexmock>=0.9.7:../../devel/py-flexmock
DEPENDS+=	${PYPKGPREFIX}-psycopg2>=2.5.1:../../databases/py-psycopg2
DEPENDS+=	${PYPKGPREFIX}-pytz>=2014.2:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-pymysql-[0-9]*:../../databases/py-pymysql
DEPENDS+=	${PYPKGPREFIX}-arrow>=0.3.4:../../time/py-arrow
DEPENDS+=	${PYPKGPREFIX}-babel>=1.3:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-colour>=0.0.4:../../textproc/py-colour
DEPENDS+=	${PYPKGPREFIX}-furl>=0.3.5:../../www/py-furl
DEPENDS+=	${PYPKGPREFIX}-intervals>=0.2.4:../../math/py-intervals
DEPENDS+=	${PYPKGPREFIX}-ipaddr-[0-9]*:../../devel/py-ipaddr
DEPENDS+=	${PYPKGPREFIX}-anyjson>=0.3.3:../../textproc/py-anyjson
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.6<2.0:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-phonenumbers>=5.9.2:../../textproc/py-phonenumbers
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
.endif

.if !empty(PKG_OPTIONS:Mtimezone)
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
.endif
