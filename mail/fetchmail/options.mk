# $NetBSD: options.mk,v 1.9 2005/05/24 19:01:34 frueauf Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fetchmail
PKG_SUPPORTED_OPTIONS=	inet6 kerberos4 kerberos gssapi ssl

PKG_SUGGESTED_OPTIONS= ssl

.include "../../mk/bsd.options.mk"

###
### IPv6 support.
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-inet6
.endif

###
### Authentication via GSSAPI (currently only over Kerberos V) support.
###
.if !empty(PKG_OPTIONS:Mgssapi)
PKG_OPTIONS+=		kerberos
CONFIGURE_ARGS+=	--with-gssapi=${KRB5BASE}
.else
CONFIGURE_ARGS+=	--with-gssapi=no
.endif

###
### KPOP (POP3 + Kerberos IV) support.
###
.if !empty(PKG_OPTIONS:Mkerberos4)
PKG_USE_KERBEROS=	# defined
CONFIGURE_ARGS+=	--with-kerberos=yes
.  if empty(MACHINE_PLATFORM:MNetBSD-1.[0-4]*-i386)
REPLACE_KERBEROS_LIBS=	yes
.  endif
.else
CONFIGURE_ARGS+=	--with-kerberos=no
.endif

###
### Kerberos V support.
###
.if !empty(PKG_OPTIONS:Mkerberos)
.  include "../../mk/krb5.buildlink3.mk"
PKG_USE_KERBEROS=	# defined
CONFIGURE_ARGS+=        --with-kerberos5=${KRB5BASE}
.else
CONFIGURE_ARGS+=        --with-kerberos5=no
.endif

###
### Support POP3 and IMAP over SSL.
###
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif
