# $NetBSD: options.mk,v 1.5 2019/09/02 13:19:49 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.Radicale

# Cannot be supported while it results in no valid python versions.
#PKG_SUPPORTED_OPTIONS=	ldap

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mldap)
PYTHON_VERSIONS_ACCEPTED=	 27 # py-ldap
DEPENDS+=	${PYPKGPREFIX}-ldap-[0-9]*:../../databases/py-ldap
.endif
