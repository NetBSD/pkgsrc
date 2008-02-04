# $NetBSD: options.mk,v 1.2 2008/02/04 15:29:28 ghen Exp $

PKG_SUPPORTED_OPTIONS+=		# empty

.include "../../mk/bsd.options.mk"

###
### PAM authentication for the PostgreSQL backend.
###
.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pam
.endif

###
### LDAP authentication for the PostgreSQL backend.
###
.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap
.endif
