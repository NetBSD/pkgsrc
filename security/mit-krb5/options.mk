# $NetBSD: options.mk,v 1.1 2019/07/12 15:40:55 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mit-krb5
PKG_SUPPORTED_OPTIONS=	ldap

PLIST_VARS+=		ldap

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mldap)
PLIST.ldap=		yes
CONFIGURE_ARGS+=	--with-ldap
.include "../../databases/openldap-client/buildlink3.mk"
.else
CONFIGURE_ARGS+=        --without-ldap
.endif
