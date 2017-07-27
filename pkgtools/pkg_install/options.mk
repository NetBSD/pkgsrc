# $NetBSD: options.mk,v 1.5 2017/07/27 18:54:44 tnn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libfetch
PKG_SUPPORTED_OPTIONS=	inet6 openssl
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../security/openssl/builtin.mk"

.if !empty(USE_BUILTIN.openssl:M[yY][eE][sS])
PKG_SUGGESTED_OPTIONS+=	openssl
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
MAKE_ENV+=		FETCH_WITH_INET6=yes
.else
MAKE_ENV+=		FETCH_WITH_INET6=no
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
CONFIGURE_ARGS+=	--with-ssl
MAKE_ENV+=		FETCH_WITH_OPENSSL=yes
LDFLAGS+=		-lssl -lcrypto

.include "../../security/openssl/buildlink3.mk"
.else
LIBARCHIVE_CONFIGURE_ARGS+=	--without-openssl
MAKE_ENV+=		FETCH_WITH_OPENSSL=no
.endif
