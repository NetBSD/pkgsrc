# $NetBSD: options.mk,v 1.1 2021/02/11 10:05:13 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ups-nut
PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		nss # openssl # only has openssl 1.0 support
PKG_SUGGESTED_OPTIONS=		nss

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenssl)
CONFIGURE_ARGS+=	--with-ssl=openssl --with-openssl --without-nss
.  include "../../security/openssl/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mnss)
CONFIGURE_ARGS+=	--with-ssl=nss --with-nss --without-openssl
.  include "../../devel/nss/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ssl
.endif
