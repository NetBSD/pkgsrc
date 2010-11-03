# $NetBSD: options.mk,v 1.4 2010/11/03 14:36:39 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.postgresql83
PKG_SUPPORTED_OPTIONS=	gssapi krb5 ldap pam

.include "../../mk/bsd.options.mk"

###
### GSSAPI authentication for the PostgreSQL backend.
###
.if !empty(PKG_OPTIONS:Mgssapi)
CONFIGURE_ARGS+=	--with-gssapi
.endif

###
### Kerberos5 authentication for the PostgreSQL backend.
###
.if !empty(PKG_OPTIONS:Mkrb5)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--with-krb5
.endif

###
### LDAP authentication for the PostgreSQL backend.
###
.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap
.endif

###
### PAM authentication for the PostgreSQL backend.
###
.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
.endif
