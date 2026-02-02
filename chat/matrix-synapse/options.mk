# $NetBSD: options.mk,v 1.6 2026/02/02 21:07:36 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.matrix-synapse
PKG_SUPPORTED_OPTIONS=	saml2
PKG_SUGGESTED_OPTIONS=	#

.include "../../mk/bsd.options.mk"

#
# SAML2 Single Sign-On support
#
.if !empty(PKG_OPTIONS:Msaml2)
DEPENDS+=	${PYPKGPREFIX}-pysaml2>=4.5.0:../../www/py-pysaml2
DEPENDS+=	${PYPKGPREFIX}-defusedxml>=0.7.1:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-xmlschema>=2018.3:../../textproc/py-xmlschema
.endif
