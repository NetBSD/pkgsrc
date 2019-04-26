# $NetBSD: options.mk,v 1.4 2019/04/26 13:14:07 maya Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.Radicale

# Cannot be supported while it results in no valid python versions.
#PKG_SUPPORTED_OPTIONS=	ldap

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mldap)
PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # py-ldap
DEPENDS+=	${PYPKGPREFIX}-ldap-[0-9]*:../../databases/py-ldap
.endif
