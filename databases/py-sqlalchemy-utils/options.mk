# $NetBSD: options.mk,v 1.11 2024/10/14 07:19:43 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-sqlalchemy-utils
PKG_SUPPORTED_OPTIONS=	arrow babel furl intervals ipaddress password
PKG_SUPPORTED_OPTIONS+=	phone timezone
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Marrow)
DEPENDS+=	${PYPKGPREFIX}-arrow>=0.3.4:../../time/py-arrow
.endif

.if !empty(PKG_OPTIONS:Mbabel)
DEPENDS+=	${PYPKGPREFIX}-babel>=1.3:../../devel/py-babel
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

.if !empty(PKG_OPTIONS:Mpassword)
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.6<2.0:../../security/py-passlib
.endif

.if !empty(PKG_OPTIONS:Mphone)
DEPENDS+=	${PYPKGPREFIX}-phonenumbers>=5.9.2:../../textproc/py-phonenumbers
.endif

.if !empty(PKG_OPTIONS:Mtimezone)
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
.endif
