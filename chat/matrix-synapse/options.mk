# $NetBSD: options.mk,v 1.5 2024/10/14 06:45:32 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.matrix-synapse
PKG_SUPPORTED_OPTIONS=	saml2
PKG_SUGGESTED_OPTIONS=	#

.include "../../mk/bsd.options.mk"

#
# SAML2 Single Sign-On support
#
.if !empty(PKG_OPTIONS:Msaml2)
DEPENDS+=	${PYPKGPREFIX}-pysaml2-[0-9]*:../../www/py-pysaml2
DEPENDS+=	${PYPKGPREFIX}-defusedxml-[0-9]*:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-xmlschema-[0-9]*:../../textproc/py-xmlschema
.endif
