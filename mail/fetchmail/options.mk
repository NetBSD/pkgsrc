# $NetBSD: options.mk,v 1.3 2004/08/22 19:32:51 jlam Exp $

.if defined(KERBEROS)
PKG_DEFAULT_OPTIONS+=	kerberos4
.endif
.if defined(USE_INET6) && !empty(USE_INET6:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	inet6
.endif
.if defined(FETCHMAIL_USE_SSL) && !empty(FETCHMAIL_USE_SSL:M[yY][eE][sS])
PKG_DEFAULT_OPTIONS+=	ssl
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.fetchmail
PKG_SUPPORTED_OPTIONS=	inet6 kerberos4 ssl

.if !defined(PKG_OPTIONS.fetchmail)
PKG_DEFAULT_OPTIONS+=	inet6 ssl
.endif

.include "../../mk/bsd.options.mk"

###
### IPv6 support.
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-inet6
.endif

###
### KPOP (POP3 + Kerberos 4) support.
###
.if !empty(PKG_OPTIONS:Mkerberos4)
CRYPTO+=		uses Kerberos encryption code
CONFIGURE_ARGS+=	--with-kerberos=yes
.  if empty(MACHINE_PLATFORM:MNetBSD-1.[0-4]*-i386)
REPLACE_KERBEROS_LIBS=	yes
.  endif
.else
CONFIGURE_ARGS+=	--with-kerberos=no
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
