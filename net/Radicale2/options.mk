# $NetBSD: options.mk,v 1.2 2017/07/12 07:30:46 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.Radicale

# Cannot be supported while it results in no valid python versions.
#PKG_SUPPORTED_OPTIONS=	ldap

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mldap)
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-ldap
DEPENDS+=	${PYPKGPREFIX}-ldap-[0-9]*:../../databases/py-ldap
.endif
