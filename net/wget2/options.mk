# $NetBSD: options.mk,v 1.1 2021/10/03 13:41:11 ryoon Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.wget2
PKG_SUPPORTED_OPTIONS=		gpgme http2 idn psl
PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		gnutls openssl
PKG_SUGGESTED_OPTIONS=		http2 idn openssl psl

.include "../../mk/bsd.options.mk"

###
### Support IDN
###
.if !empty(PKG_OPTIONS:Midn)
.include "../../devel/libidn2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libidn2
.else
CONFIGURE_ARGS+=	--without-libidn2
.endif

###
### Support SSL
### Current configuration of security/wolfssl is not compatible.
###
.if !empty(PKG_OPTIONS:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=--with-ssl=gnutls
.elif !empty(PKG_OPTIONS:Mopenssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=--with-ssl=openssl
.else
CONFIGURE_ARGS+=--with-ssl=no
.endif

###
### Support signature verification with gpgme
###
.if !empty(PKG_OPTIONS:Mgpgme)
.  include "../../security/gpgme/buildlink3.mk"
CONFIGURE_ARGS+=--with-gpgme
.else
CONFIGURE_ARGS+=--without-gpgme
.endif

###
### Support HTTP/2
###
.if !empty(PKG_OPTIONS:Mhttp2)
.  include "../../www/nghttp2/buildlink3.mk"
CONFIGURE_ARGS+=--with-libnghttp2
.else
CONFIGURE_ARGS+=--without-libnghttp2
.endif

###
### Support Public Suffix List
###
.if !empty(PKG_OPTIONS:Mpsl)
.  include "../../www/libpsl/buildlink3.mk"
CONFIGURE_ARGS+=--with-libpsl
.else
CONFIGURE_ARGS+=--without-libpsl
.endif
