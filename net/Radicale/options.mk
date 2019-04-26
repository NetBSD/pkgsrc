# $NetBSD: options.mk,v 1.8 2019/04/26 13:14:06 maya Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.Radicale
PKG_SUPPORTED_OPTIONS=	git ldap

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgit)
DEPENDS+=	${PYPKGPREFIX}-dulwich-[0-9]*:../../devel/py-dulwich
.endif

.if !empty(PKG_OPTIONS:Mldap)
PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # py-ldap
DEPENDS+=	${PYPKGPREFIX}-ldap-[0-9]*:../../databases/py-ldap
.endif
