# $NetBSD: options.mk,v 1.5 2009/10/31 02:29:14 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.wget
PKG_SUPPORTED_OPTIONS=	idn inet6 ssl
PKG_SUGGESTED_OPTIONS=	idn ssl

.include "../../mk/bsd.options.mk"

###
### Support IDN
###
.if !empty(PKG_OPTIONS:Midn)
.include "../../devel/libidn/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
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
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=--with-ssl=${SSLBASE:Q}
.else
CONFIGURE_ARGS+=--without-ssl
.endif
