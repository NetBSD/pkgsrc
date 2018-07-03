# $NetBSD: options.mk,v 1.3 2018/07/03 05:03:26 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.Radicale

# Cannot be supported while it results in no valid python versions.
#PKG_SUPPORTED_OPTIONS=	ldap

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mldap)
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-ldap
DEPENDS+=	${PYPKGPREFIX}-ldap-[0-9]*:../../databases/py-ldap
.endif
