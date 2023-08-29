# $NetBSD: options.mk,v 1.2 2023/08/29 14:10:25 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.matrix-synapse
PKG_SUPPORTED_OPTIONS=  saml2
PKG_SUGGESTED_OPTIONS=	#

.include "../../mk/bsd.options.mk"

#
# Add SQLite 3 support
#
.if !empty(PKG_OPTIONS:Msaml2)
PYTHON_VERSIONS_INCOMPATIBLE+=	38 # py-pysaml2
DEPENDS+=	${PYPKGPREFIX}-pysaml2-[0-9]*:../../www/py-pysaml2
DEPENDS+=	${PYPKGPREFIX}-defusedxml-[0-9]*:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-xmlschema-[0-9]*:../../textproc/py-xmlschema
.endif
