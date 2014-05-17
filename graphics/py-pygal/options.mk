# $NetBSD: options.mk,v 1.1 2014/05/17 13:59:37 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-pygal
PKG_SUPPORTED_OPTIONS=	png tests
PKG_SUGGESTED_OPTIONS+=	png

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpng)
DEPENDS+=	${PYPKGPREFIX}-cairosvg-[0-9]*:../../converters/py-cairosvg
DEPENDS+=	${PYPKGPREFIX}-tinycss-[0-9]*:../../textproc/py-tinycss
DEPENDS+=	${PYPKGPREFIX}-cssselect-[0-9]*:../../textproc/py-cssselect
.endif

.if !empty(PKG_OPTIONS:Mtests)
DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-pyquery-[0-9]*:../../textproc/py-pyquery
DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-cairosvg-[0-9]*:../../converters/py-cairosvg
.endif
