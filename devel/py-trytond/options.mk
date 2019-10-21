# $NetBSD: options.mk,v 1.16 2019/10/21 21:45:40 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-trytond
PKG_SUPPORTED_OPTIONS=	cdecimal mysql pydot psycopg pytz simplejson sphinx
PKG_SUGGESTED_OPTIONS+=	psycopg pytz simplejson sphinx

.include "../../mk/bsd.options.mk"

# XXX: Supports unoconv http://dag.wieers.com/home-made/unoconv/) option and
# XXX: python-Levenshtein (http://github.com/miohtama/python-Levenshtein) option

.if !empty(PKG_OPTIONS:Mcdecimal)
PYTHON_VERSIONS_ACCEPTED=	27 # py-cdecimal is obsolete for that version and thus not available
DEPENDS+=		${PYPKGPREFIX}-cdecimal-[0-9]*:../../math/py-cdecimal
.endif

.if !empty(PKG_OPTIONS:Mmysql)
PYTHON_VERSIONS_ACCEPTED=	27 # py-mysqldb
DEPENDS+=		${PYPKGPREFIX}-mysqldb-[0-9]*:../../databases/py-mysqldb
.endif

.if !empty(PKG_OPTIONS:Mpydot)
DEPENDS+=		${PYPKGPREFIX}-dot-[0-9]*:../../graphics/py-dot
.endif

.if !empty(PKG_OPTIONS:Mpsycopg)
DEPENDS+=		${PYPKGPREFIX}-psycopg2>=2:../../databases/py-psycopg2
.endif

.if !empty(PKG_OPTIONS:Mpytz)
DEPENDS+=		${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
.endif

.if !empty(PKG_OPTIONS:Msimplejson)
DEPENDS+=		${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson
.endif

.if !empty(PKG_OPTIONS:Msphinx)
PYTHON_VERSIONED_DEPENDENCIES=	sphinx
.include "../../lang/python/versioned_dependencies.mk"
.endif
