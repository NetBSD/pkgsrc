# $NetBSD: options.mk,v 1.1 2004/08/30 20:16:28 adrianp Exp $

# Global and legacy options
.if defined(USE_DB2) && !empty(USE_DB2:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	db2
.	elif defined(USE_DB4) && !empty(USE_DB4:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	db4
.endif
.if defined(USE_OPENLDAP) && !empty(USE_OPENLDAP:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	ldap
.endif
.if defined(USE_SASL) && !empty(USE_SASL:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	sasl
.	elif defined(USE_SASL2) && !empty(USE_SASL2:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	sasl2
.endif
.if defined(USE_TCPWRAPPERS) && !empty(USE_TCPWRAPPERS:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	tcpwrappers
.endif
.if defined(USE_INET6) && !empty(USE_INET6:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	inet6
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.sendmail
PKG_SUPPORTED_OPTIONS=	inet6 db2 db4 ldap sasl sasl2 starttls tcpwrappers \
			socketmap

.if !defined(PKG_OPTIONS.sendmail)
PKG_DEFAULT_OPTIONS+=	inet6 tcpwrappers
.endif

.include "../../mk/bsd.options.mk"

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
