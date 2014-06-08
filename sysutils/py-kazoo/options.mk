# $NetBSD: options.mk,v 1.1 2014/06/08 22:51:04 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-kazoo
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.include "../../lang/python/pyversion.mk"

.if !empty(PKG_OPTIONS:Mtests)
DEPENDS+=		${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
DEPENDS+=		${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=		${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
DEPENDS+=		${PYPKGPREFIX}-gevent-[0-9]*:../../net/py-gevent
.endif
