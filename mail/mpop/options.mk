# $NetBSD: options.mk,v 1.3 2018/11/20 09:29:24 maya Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.mpop
PKG_SUPPORTED_OPTIONS=		gsasl idn
PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		gnutls ssl
PKG_SUGGESTED_OPTIONS=		ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+=	--with-tls=gnutls
.  include "../../security/gnutls/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--with-tls=openssl
.  include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-tls
.endif

.if !empty(PKG_OPTIONS:Mgsasl)
CONFIGURE_ARGS+=	--enable-gsasl
.  include "../../security/gsasl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Midn)
.  include "../../devel/libidn/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libidn
CONFIGURE_ARGS+=	--with-libidn-prefix=${BUILDLINK_PREFIX.libidn}
.else
CONFIGURE_ARGS+=	--without-libidn
.endif
