# $NetBSD: options.mk,v 1.2 2015/04/18 02:43:24 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ucommon
PKG_SUPPORTED_OPTIONS=	gnutls openssl static tests
PKG_SUGGESTED_OPTIONS+=	openssl
PLIST_VARS+=		dynamic static

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=3.0.0
.include "../../security/gnutls/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
BUILDLINK_API_DEPENDS.openssl+=	openssl>=1.0.0
.include "../../security/openssl/buildlink3.mk"
CMAKE_ARGS+=	-DCRYPTO_OPENSSL=ON
.else
CMAKE_ARGS+=	-DCRYPTO_OPENSSL=OFF
.endif

.if !empty(PKG_OPTIONS:Mstatic)
CMAKE_ARGS+=	-DBUILD_STATIC=ON -DCRYPTO_STATIC=ON
PLIST.static=	yes
.else
CMAKE_ARGS+=	-DBUILD_STATIC=OFF -DCRYPTO_STATIC=OFF
PLIST.dynamic=	yes
.endif

.if !empty(PKG_OPTIONS:Mtests)
CMAKE_ARGS+=	-DBUILD_TESTING=ON
.else
CMAKE_ARGS+=	-DBUILD_TESTING=OFF
.endif
