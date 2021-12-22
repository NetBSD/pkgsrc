# $NetBSD: options.mk,v 1.15 2021/12/22 22:41:18 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-tryton
PKG_SUPPORTED_OPTIONS=	goocalendar
PKG_SUGGESTED_OPTIONS+=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgoocalendar)
DEPENDS+=		${PYPKGPREFIX}-goocalendar-[0-9]*:../../time/py-goocalendar
.endif
