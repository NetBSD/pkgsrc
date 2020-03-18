# $NetBSD: options.mk,v 1.1 2020/03/18 00:29:38 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ldb
PKG_SUPPORTED_OPTIONS=	ldap
PKG_SUGGESTED_OPTIONS=	ldap

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		ldap

.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
PLIST.ldap=		yes
.endif
