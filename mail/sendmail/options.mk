# $NetBSD: options.mk,v 1.21 2014/06/15 20:48:49 jnemeth Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sendmail
PKG_SUPPORTED_OPTIONS=	inet6 db2 db4 ldap sasl tls tcpwrappers ffr-tls
PKG_SUGGESTED_OPTIONS=	inet6 tcpwrappers

PKG_OPTIONS_LEGACY_OPTS+=	starttls:tls ffr_tls_1:ffr-tls

.include "../../mk/bsd.options.mk"

###
### Berkeley DB version 2/4 format for on disk databases e.g. aliases
###
.if !empty(PKG_OPTIONS:Mdb2)
.  include "../../databases/db/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mdb4)
.  include "../../databases/db4/buildlink3.mk"
.endif

###
### Use OpenLDAP for remote database access
###
.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
.endif

###
### Use SASL/v2 for SMTP AUTH
###
.if !empty(PKG_OPTIONS:Msasl)
.  include "../../security/cyrus-sasl/buildlink3.mk"
.endif

###
### Use OpenSSL libraries for SMTP STARTTLS support
###
.if !empty(PKG_OPTIONS:Mtls)
.  include "../../security/openssl/buildlink3.mk"
.endif

###
### 'For Future Release' FFR_TLS_* options: CipherList, multiple certs
###
# Nothing to do here, activation is done in Makefile

###
### Use tcpwrappers for network access control to sendmail
###
.if !empty(PKG_OPTIONS:Mtcpwrappers)
.  include "../../security/tcp_wrappers/buildlink3.mk"
.endif

###
### IPv6 support.
###
.if !empty(PKG_OPTIONS:Minet6)
.endif
