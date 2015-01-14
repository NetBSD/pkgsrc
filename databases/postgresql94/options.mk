# $NetBSD: options.mk,v 1.1 2015/01/14 21:01:18 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.postgresql94
PKG_SUPPORTED_OPTIONS=	bonjour gssapi kerberos ldap pam xml dtrace

.include "../../mk/bsd.options.mk"

###
### Bonjour support.
###
.if !empty(PKG_OPTIONS:Mbonjour)
CONFIGURE_ARGS+=	--with-bonjour
.  if ${OPSYS} != "Darwin"
LIBS+=			-ldns_sd
.  endif
.  include "../../net/mDNSResponder/buildlink3.mk"
.endif

###
### GSSAPI authentication for the PostgreSQL backend.
###
.if !empty(PKG_OPTIONS:Mgssapi)
CONFIGURE_ARGS+=	--with-gssapi
.endif

###
### Kerberos5 authentication for the PostgreSQL backend.
###
.if !empty(PKG_OPTIONS:Mkerberos)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--with-krb5

CHECK_BUILTIN.${KRB5_TYPE}:=	yes
.include	"../../security/${KRB5_TYPE}/builtin.mk"
CHECK_BUILTIN.${KRB5_TYPE}:=	no

.	if !empty(USE_BUILTIN.${KRB5_TYPE}:M[yY][eE][sS]) && \
		exists(${SH_KRB5_CONFIG})
CFLAGS_KRB5!=	${SH_KRB5_CONFIG} --cflags
CPPFLAGS+=	${CFLAGS_KRB5}
.	endif
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
CONFIGURE_ARGS+=	--with-libxml
.endif

###
### Dtrace support
###
.if !empty(PKG_OPTIONS:Mdtrace)
CONFIGURE_ARGS+=	--enable-dtrace
.endif
