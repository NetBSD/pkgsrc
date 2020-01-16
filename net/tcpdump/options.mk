# $NetBSD: options.mk,v 1.5 2020/01/16 13:33:51 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tcpdump
PKG_SUPPORTED_OPTIONS=	ssl libsmi
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-crypto
.endif

.if !empty(PKG_OPTIONS:Mlibsmi)
.include "../../devel/libsmi/buildlink3.mk"
.endif
