# $NetBSD: options.mk,v 1.2 2015/01/28 20:39:54 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.Radicale
PKG_SUPPORTED_OPTIONS=	git ldap

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgit)
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-dulwich
DEPENDS+=	${PYPKGPREFIX}-dulwich-[0-9]*:../../devel/py-dulwich
.endif

.if !empty(PKG_OPTIONS:Mldap)
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-ldap
DEPENDS+=	${PYPKGPREFIX}-ldap-[0-9]*:../../databases/py-ldap
.endif
