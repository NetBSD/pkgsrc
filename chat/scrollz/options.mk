# $NetBSD: options.mk,v 1.4 2020/05/31 17:22:16 rillig Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.scrollz
PKG_SUPPORTED_OPTIONS=		regexp utf8
PKG_SUGGESTED_OPTIONS+=		inet6
PKG_OPTIONS_OPTIONAL_GROUPS=	conflict socks ssl
PKG_OPTIONS_GROUP.socks=	socks4 dante
PKG_OPTIONS_GROUP.ssl=		gnutls openssl
# PR 52883: these two options conflict
PKG_OPTIONS_GROUP.conflict=	efence inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mefence)
.include "../../devel/electric-fence/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-fish --with-ssl
.else
CONFIGURE_ARGS+=	--disable-fish --without-ssl
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--disable-fish --with-openssl
.else
CONFIGURE_ARGS+=	--without-openssl
.endif

.if !empty(PKG_OPTIONS:Mregexp)
CONFIGURE_ARGS+=	--enable-regexp
.else
CONFIGURE_ARGS+=	--disable-regexp
.endif

.if !empty(PKG_OPTIONS:Msocks4)
.include "../../net/socks4/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdante)
.include "../../net/dante/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mutf8)
.include "../../converters/libiconv/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-utf8
LIBS+=			-liconv
.else
CONFIGURE_ARGS+=	--disable-utf8
.endif
