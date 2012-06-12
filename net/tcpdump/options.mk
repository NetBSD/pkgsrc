# $NetBSD: options.mk,v 1.3 2012/06/12 15:46:01 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tcpdump
PKG_SUPPORTED_OPTIONS=	inet6 ssl libsmi
PKG_SUGGESTED_OPTIONS=	inet6 ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mssl)
USE_OLD_DES_API=	yes
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-crypto
.endif

.if !empty(PKG_OPTIONS:Mlibsmi)
.include "../../devel/libsmi/buildlink3.mk"
.endif
