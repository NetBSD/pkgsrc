# $NetBSD: options.mk,v 1.5 2019/04/26 13:14:06 maya Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-trytond-party
PKG_SUPPORTED_OPTIONS=	vatnumber
PKG_SUGGESTED_OPTIONS+=	vatnumber

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mvatnumber)
PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # py-simplesoap via py-stdnum and py-vatnumber
DEPENDS+=	${PYPKGPREFIX}-vatnumber-[0-9]*:../../finance/py-vatnumber
.endif
