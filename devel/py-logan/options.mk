# $NetBSD: options.mk,v 1.1 2015/04/01 02:39:02 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-logan
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
DEPENDS+=	${PYPKGPREFIX}-django>=1.5:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-mock>=0.8.0:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-nose>=1.1.2:../../devel/py-nose
.endif
