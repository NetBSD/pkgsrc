# $NetBSD: options.mk,v 1.2 2024/05/05 21:01:04 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sendmail
PKG_SUPPORTED_OPTIONS=	inet6 db2 db4 ldap sasl tls tcpwrappers
PKG_SUPPORTED_OPTIONS+=	sendmail-ffr-tls sendmail-ffr-badrcptshutdown
PKG_SUPPORTED_OPTIONS+=	smtputf8
PKG_SUGGESTED_OPTIONS=	inet6 tcpwrappers tls

.include "../../mk/bsd.prefs.mk"

.for dir in ${COMPILER_INCLUDE_DIRS}
.  if exists(${dir}/blacklist.h)
PKG_SUPPORTED_OPTIONS+=		blacklist
#PKG_SUGGESTED_OPTIONS+=		blacklist
PKG_OPTIONS_LEGACY_OPTS+=	blacklistd:blacklist
.  endif
.endfor

PKG_OPTIONS_LEGACY_OPTS+=	starttls:tls ffr_tls_1:sendmail-ffr-tls

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
### 'For Future Release' _FFR_TLS_* options: CipherList, multiple certs
###
# Nothing to do here, activation is done in Makefile

###
### 'For Future Release' _FFR_BADRCPT_SHUTDOWN options:
###      BadRcptShutdown, BadRcptShutdownGood
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

###
### NetBSD blacklistd(8) support.
###
# Nothing to do here, activation is done in Makefile

###
### SMTPUTF8 support
###
.if !empty(PKG_OPTIONS:Msmtputf8)
.  include "../../textproc/icu/buildlink3.mk"
.endif

