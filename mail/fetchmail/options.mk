# $NetBSD: options.mk,v 1.1 2004/08/05 02:31:24 jlam Exp $

# Global and legacy options
.if defined(KERBEROS) && defined(USE_INET6) || defined(FETCHMAIL_USE_SSL)
.  if !defined(PKG_OPTIONS.fetchmail)
.    if defined(KERBEROS)
PKG_OPTIONS.fetchmail+=	kerberos4
.    endif
.    if defined(USE_INET6) && !empty(USE_INET6:M[yY][eE][sS])
PKG_OPTIONS.fetchmail+=	inet6
.    endif
.    if defined(FETCHMAIL_USE_SSL) && !empty(FETCHMAIL_USE_SSL:M[yY][eE][sS])
PKG_OPTIONS.fetchmail+=	ssl
.    endif
.  endif
.endif
PKG_OPTIONS.fetchmail?=	inet6 ssl

PKG_OPTIONS_VAR=	PKG_OPTIONS.fetchmail
PKG_SUPPORTED_OPTIONS=	inet6 kerberos4 ssl
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
