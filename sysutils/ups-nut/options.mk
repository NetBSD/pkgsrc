# $NetBSD: options.mk,v 1.3 2023/11/09 21:02:48 gdt Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ups-nut
PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		nss openssl
PKG_SUGGESTED_OPTIONS=		openssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnss)
CONFIGURE_ARGS+=	--with-ssl=nss --with-nss --without-openssl
.  include "../../devel/nss/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mopenssl)
CONFIGURE_ARGS+=	--with-ssl=openssl --without-nss --with-openssl
.  include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ssl
.endif
