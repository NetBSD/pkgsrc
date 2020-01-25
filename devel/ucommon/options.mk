# $NetBSD: options.mk,v 1.4 2020/01/25 10:45:10 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ucommon
PKG_SUPPORTED_OPTIONS=	gnutls openssl tests
PKG_SUGGESTED_OPTIONS+=	openssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=3.0.0
.include "../../security/gnutls/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
CMAKE_ARGS+=	-DCRYPTO_OPENSSL=ON
.else
CMAKE_ARGS+=	-DCRYPTO_OPENSSL=OFF
.endif

.if !empty(PKG_OPTIONS:Mtests)
CMAKE_ARGS+=	-DBUILD_TESTING=ON
.else
CMAKE_ARGS+=	-DBUILD_TESTING=OFF
.endif
