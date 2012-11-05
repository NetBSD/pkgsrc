# $NetBSD: options.mk,v 1.15.44.1 2012/11/05 09:06:58 spz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fetchmail
PKG_SUPPORTED_OPTIONS=	kerberos4 kerberos gssapi ssl
PKG_OPTIONS_OPTIONAL_GROUPS=	socks
PKG_OPTIONS_GROUP.socks=	socks4 socks5

PKG_SUGGESTED_OPTIONS= ssl

.include "../../mk/bsd.options.mk"

###
### Authentication via GSSAPI (currently only over Kerberos V) support.
###
.if !empty(PKG_OPTIONS:Mgssapi)
CONFIGURE_ARGS+=	--with-gssapi=${KRB5BASE:Q}
.else
CONFIGURE_ARGS+=	--with-gssapi=no
.endif

###
### KPOP (POP3 + Kerberos IV) support.
###
.if !empty(PKG_OPTIONS:Mkerberos4)
PKG_USE_KERBEROS=	yes
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
.if !empty(PKG_OPTIONS:Mkerberos) || !empty(PKG_OPTIONS:Mgssapi)
.  include "../../mk/krb5.buildlink3.mk"
PKG_USE_KERBEROS=	yes
CONFIGURE_ARGS+=        --with-kerberos5=${KRB5BASE:Q}
.else
CONFIGURE_ARGS+=        --with-kerberos5=no
.endif

###
### Support POP3 and IMAP over SSL.
###
.if !empty(PKG_OPTIONS:Mssl)
.  if !empty(MACHINE_PLATFORM:MNetBSD-[1-5].*-*)
# "fetchmail" requires the "SSL_CTX_clear_options" library function which
# was added in OpenSSL 0.9.8m. NetBSD 5.* ships with a snapshot that
# claims to be OpenSSL 0.9.9 but doesn't provide this function. Force
# the use of the "openssl" package to fix the build.
USE_BUILTIN.openssl=	no
.  endif
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE:Q}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

###
### Include SOCKS firewall support
###
.if !empty(PKG_OPTIONS:Msocks4)
.include "../../net/socks4/buildlink3.mk"
CONFIGURE_ARGS+=	--with-socks=${BUILDLINK_PREFIX.socks4}
.endif
.if !empty(PKG_OPTIONS:Msocks5)
.include "../../net/socks5/buildlink3.mk"
CONFIGURE_ARGS+=	--with-socks5=${BUILDLINK_PREFIX.socks5}
.endif
