# $NetBSD: options.mk,v 1.3 2010/12/11 16:16:37 asau Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.postgresql90
PKG_SUPPORTED_OPTIONS=	gssapi krb5 ldap pam xml

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

###
### XML support for the PostgreSQL backend.
###
.if !empty(PKG_OPTIONS:Mxml)
.  include "../../textproc/libxml2/buildlink3.mk"
CONFIGURE_ARGS+=        --with-libxml
.endif
