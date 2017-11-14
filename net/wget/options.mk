# $NetBSD: options.mk,v 1.10 2017/11/14 09:51:13 leot Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wget
PKG_SUPPORTED_OPTIONS=	idn inet6
PKG_OPTIONS_REQUIRED_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=	gnutls openssl
PKG_SUGGESTED_OPTIONS=	idn inet6 openssl

.include "../../mk/bsd.options.mk"

###
### Support IDN
###
.if !empty(PKG_OPTIONS:Midn)
.include "../../devel/libidn2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-iri
.else
CONFIGURE_ARGS+=	--disable-iri
.endif

###
### Support IPv6
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

###
### Support SSL
###
.if !empty(PKG_OPTIONS:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=--with-ssl=gnutls
.else
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=--with-ssl=openssl
.endif
