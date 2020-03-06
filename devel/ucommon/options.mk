# $NetBSD: options.mk,v 1.5 2020/03/06 12:12:58 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ucommon
PKG_SUPPORTED_OPTIONS=	gnutls tests
PKG_SUGGESTED_OPTIONS+=	gnutls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
CMAKE_ARGS+=	-DCRYPTO_GNUTLS=ON
BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=3.0.0
.include "../../security/gnutls/buildlink3.mk"
CMAKE_ARGS+=	-DCRYPTO_GNUTLS=OFF
.endif

.if !empty(PKG_OPTIONS:Mtests)
CMAKE_ARGS+=	-DBUILD_TESTING=ON
.else
CMAKE_ARGS+=	-DBUILD_TESTING=OFF
.endif
