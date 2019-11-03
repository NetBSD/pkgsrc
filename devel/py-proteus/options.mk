# $NetBSD: options.mk,v 1.10 2019/11/03 10:18:29 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-proteus
PKG_SUPPORTED_OPTIONS+=	cdecimal simplejson
# track py-trytond for cdecimal suggested option selection
PKG_SUGGESTED_OPTIONS+=	${PKG_DEFAULT_OPTIONS:Mcdecimal} ${PKG_OPTIONS.py-trytond:Mcdecimal}
PKG_SUGGESTED_OPTIONS+=	simplejson

.include "../../mk/bsd.options.mk"

# XXX Supports unoconv http://dag.wieers.com/home-made/unoconv/) and
# XXX python-Levenshtein (http://github.com/miohtama/python-Levenshtein) options

.if !empty(PKG_OPTIONS:Mcdecimal)
PYTHON_VERSIONS_ACCEPTED=	27 # py-cdecimal is obsolete for that version and thus not available
DEPENDS+=		${PYPKGPREFIX}-cdecimal-[0-9]*:../../math/py-cdecimal
.endif

.if !empty(PKG_OPTIONS:Msimplejson)
DEPENDS+=		${PYPKGPREFIX}-simplejson-[0-9]*:../../converters/py-simplejson
.endif
