# $NetBSD: options.mk,v 1.15 2024/05/06 11:11:53 cheusov Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.wget
PKG_SUPPORTED_OPTIONS=		idn inet6 nls psl
PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		gnutls openssl
PKG_SUGGESTED_OPTIONS=		idn inet6 nls openssl psl

PLIST_VARS+=	nls

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
.elif !empty(PKG_OPTIONS:Mopenssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=--with-ssl=openssl
.else
CONFIGURE_ARGS+=--with-ssl=no
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

###
### Support NLS
###
.if !empty(PKG_OPTIONS:Mnls)
PLIST.nls=yes
.include "../../devel/gettext-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=--disable-nls
.endif
