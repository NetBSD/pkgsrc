# $NetBSD: options.mk,v 1.7 2019/11/03 17:04:26 rillig Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-trytond-party
PKG_SUPPORTED_OPTIONS=	vatnumber
PKG_SUGGESTED_OPTIONS+=	vatnumber

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mvatnumber)
PYTHON_VERSIONS_ACCEPTED= 27 # py-simplesoap via py-stdnum and py-vatnumber
DEPENDS+=	${PYPKGPREFIX}-vatnumber-[0-9]*:../../finance/py-vatnumber
.endif
