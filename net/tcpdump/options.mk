# $NetBSD: options.mk,v 1.4 2017/09/08 11:10:41 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tcpdump
PKG_SUPPORTED_OPTIONS=	ssl libsmi
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl)
USE_OLD_DES_API=	yes
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-crypto
.endif

.if !empty(PKG_OPTIONS:Mlibsmi)
.include "../../devel/libsmi/buildlink3.mk"
.endif
