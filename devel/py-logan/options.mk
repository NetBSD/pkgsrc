# $NetBSD: options.mk,v 1.2 2015/04/01 11:36:00 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-logan
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.include "../../lang/python/pyversion.mk"

.if !empty(PKG_OPTIONS:Mtests)
DEPENDS+=	${PYPKGPREFIX}-django>=1.5:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-mock>=0.8.0:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-nose>=1.1.2:../../devel/py-nose
.endif
