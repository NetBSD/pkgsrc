# $NetBSD: options.mk,v 1.1 2004/08/23 21:15:17 xtraeme Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.sudo
PKG_SUPPORTED_OPTIONS=	kerberos ldap pam
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mkerberos)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--without-kerb4
CONFIGURE_ARGS+=	--with-kerb5
.else
CONFIGURE_ARGS+=	--without-kerb5
.endif

.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap}
.endif

.if !empty(PKG_OPTIONS:Mpam)
.  include "../../security/PAM/buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
.endif
