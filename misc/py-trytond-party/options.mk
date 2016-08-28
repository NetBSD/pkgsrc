# $NetBSD: options.mk,v 1.2 2016/08/28 15:48:33 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-trytond-party
PKG_SUPPORTED_OPTIONS=	vatnumber
PKG_SUGGESTED_OPTIONS+=	vatnumber

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mvatnumber)
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-simplesoap via py-stdnum and py-vatnumber
DEPENDS+=	${PYPKGPREFIX}-vatnumber-[0-9]*:../../finance/py-vatnumber
.endif
