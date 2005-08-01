# $NetBSD: options.mk,v 1.1 2005/08/01 14:54:33 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sendmail
PKG_OPTIONS_OPTIONAL_GROUPS=	database
PKG_OPTIONS_GROUP.database=	db2 db4
PKG_SUPPORTED_OPTIONS=	inet6 ldap sasl tls tcpwrappers socketmap
PKG_SUGGESTED_OPTIONS=	tcpwrappers

PKG_OPTIONS_LEGACY_OPTS+=	starttls:tls
PKG_OPTIONS_LEGACY_VARS+=	USE_STARTTLS:ssl
PKG_OPTIONS_LEGACY_VARS+=	USE_TCPWRAPPERS:tcpwrappers

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
PKG_SUGGEST_OPTIONS+=	db2
.endif

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
.  include "../../databases/openldap/buildlink3.mk"
.endif

###
### Use SASL/v2 for SMTP AUTH
###
.if !empty(PKG_OPTIONS:Msasl)
.  include "../../security/cyrus-sasl2/buildlink3.mk"
.endif

###
### Use OpenSSL libraries for SMTP STARTTLS support
###
.if !empty(PKG_OPTIONS:Mtls)
.  include "../../security/openssl/buildlink3.mk"
.endif

###
### Use tcpwrappers for network access control to sendmail
###
.if !empty(PKG_OPTIONS:Mtcpwrappers)
.  include "../../security/tcp_wrappers/buildlink3.mk"
.endif

###
### Enable Sendmail SOCKETMAP support
###
.if !empty(PKG_OPTIONS:Msocketmap)
USE_TOOLS+=	perl:run
REPLACE_PERL=	contrib/socketmapClient.pl contrib/socketmapServer.pl
.endif

###
### IPv6 support.
###
.if !empty(PKG_OPTIONS:Minet6)
.endif
