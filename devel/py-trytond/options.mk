# $NetBSD: options.mk,v 1.20 2023/07/03 17:33:06 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-trytond
PKG_SUPPORTED_OPTIONS=	levenshtein pydot psycopg
PKG_SUGGESTED_OPTIONS+=	levenshtein pydot psycopg

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlevenshtein)
DEPENDS+=		${PYPKGPREFIX}-Levenshtein-[0-9]*:../../textproc/py-Levenshtein
.endif

.if !empty(PKG_OPTIONS:Mpydot)
DEPENDS+=		${PYPKGPREFIX}-dot-[0-9]*:../../graphics/py-dot
.endif

.if !empty(PKG_OPTIONS:Mpsycopg)
DEPENDS+=		${PYPKGPREFIX}-psycopg2>=2.5:../../databases/py-psycopg2
.endif
