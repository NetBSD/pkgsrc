# $NetBSD: options.mk,v 1.3 2004/11/17 19:56:49 xtraeme Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sendmail
PKG_SUPPORTED_OPTIONS=	inet6 db2 db4 ldap sasl sasl2 starttls tcpwrappers \
			socketmap

.if !defined(PKG_OPTIONS.sendmail)
PKG_DEFAULT_OPTIONS+=	inet6 tcpwrappers
.endif

.include "../../mk/bsd.options.mk"

###
### Can't support SASLv1 and SASLv2
###
.if !empty(PKG_OPTIONS:Msasl) && !empty(PKG_OPTIONS:Msasl2)
PKG_FAIL_REASON+=	"SASLv1 and SASLv2 cannot both be compiled in." \
			"Please change ${PKG_OPTIONS_VAR} to one or the other."
.endif

###
### Berkeley DB version 2/4 format for on disk databases e.g. aliases
###
.if !empty(PKG_OPTIONS:Mdb2)
.	include "../../databases/db/buildlink3.mk"
.	elif !empty(PKG_OPTIONS:Mdb4)
.		include "../../databases/db4/buildlink3.mk"
.endif

###
### Use OpenLDAP for remote database access
###
.if !empty(PKG_OPTIONS:Mldap)
.	include "../../databases/openldap/buildlink3.mk"
.endif

###
### Use SASL/v2 for SMTP AUTH
###
.if !empty(PKG_OPTIONS:Msasl)
.	include "../../security/cyrus-sasl/buildlink3.mk"
.	elif !empty(PKG_OPTIONS:Msasl2)
.		include "../../security/cyrus-sasl2/buildlink3.mk"
.endif

###
### Use OpenSSL libraries for SMTP STARTTLS support
###
.if !empty(PKG_OPTIONS:Mstarttls)
.	include "../../security/openssl/buildlink3.mk"
.endif

###
### Use tcpwrappers for network access control to sendmail
###
.if !empty(PKG_OPTIONS:Mtcpwrappers)
.	include "../../security/tcp_wrappers/buildlink3.mk"
.endif

###
### Enable Sendmail SOCKETMAP support
###
.if !empty(PKG_OPTIONS:Msocketmap)
USE_PERL5=	YES
REPLACE_PERL=	contrib/socketmapClient.pl contrib/socketmapServer.pl
.endif

###
### IPv6 support.
###
.if !empty(PKG_OPTIONS:Minet6)
.endif
