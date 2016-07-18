# $NetBSD: options.mk,v 1.10 2016/07/18 15:03:05 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dovecot
PKG_SUPPORTED_OPTIONS=	kqueue pam tcpwrappers
PKG_OPTIONS_OPTIONAL_GROUPS= ssl
PKG_OPTIONS_GROUP.ssl=	gnutls ssl
PKG_SUGGESTED_OPTIONS=	pam ssl tcpwrappers

.if defined(PKG_HAVE_KQUEUE)
PKG_SUGGESTED_OPTIONS+=	kqueue
.endif
PLIST_VARS+=		ssl tcpwrappers

.include "../../mk/bsd.options.mk"

###
### Build with OpenSSL or GNU TLS as the underlying crypto library
###
.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--with-ssl=openssl
CONFIGURE_ENV+=		SSL_CFLAGS="-I${BUILDLINK_PREFIX.openssl}/include"
CONFIGURE_ENV+=		SSL_LIBS="-lssl -lcrypto"
BUILDLINK_API_DEPENDS.openssl+=openssl>=0.9.8a
.  include "../../security/openssl/buildlink3.mk"
PLIST.ssl=		yes
.elif !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+=	--with-ssl=gnutls
.  include "../../security/gnutls/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

###
### PAM support
###
.if !empty(PKG_OPTIONS:Mpam)
CONFIGURE_ARGS+=	--with-pam
.  include "../../mk/pam.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-pam
.endif

###
### kqueue support
###
.if !empty(PKG_OPTIONS:Mkqueue)
CONFIGURE_ARGS+=	--with-ioloop=kqueue
CONFIGURE_ARGS+=	--with-notify=kqueue
.else
# use the defaults
.endif

###
### tcpwrappers support
###
.if !empty(PKG_OPTIONS:Mtcpwrappers)
CONFIGURE_ARGS+=	--with-libwrap
.  include "../../security/tcp_wrappers/buildlink3.mk"
PLIST.tcpwrappers=	yes
.endif
