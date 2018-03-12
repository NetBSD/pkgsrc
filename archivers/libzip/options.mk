# $NetBSD: options.mk,v 1.1 2018/03/12 08:51:54 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libzip
PKG_OPTIONS_OPTIONAL_GROUPS=	crypto
PKG_OPTIONS_GROUP.crypto=	gnutls openssl
PKG_SUGGESTED_OPTIONS=		openssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
CMAKE_ARGS+=	-DENABLE_OPENSSL=OFF
.include "../../security/gnutls/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
CMAKE_ARGS+=	-DENABLE_GNUTLS=OFF
.include "../../security/openssl/buildlink3.mk"
.endif
