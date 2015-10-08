# $NetBSD: options.mk,v 1.1 2015/10/08 13:35:39 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnupg21
PKG_SUPPORTED_OPTIONS=	ldap
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		ldap
.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap-client}
PLIST.ldap=		yes
.include "../../databases/openldap-client/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ldap
.endif
