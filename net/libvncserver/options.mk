# $NetBSD: options.mk,v 1.3 2019/02/20 12:21:34 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libVNCServer
PKG_SUPPORTED_OPTIONS=	gnutls inet6 libgcrypt openssl sasl
PKG_SUGGESTED_OPTIONS=	gnutls inet6 libgcrypt
PKG_OPTIONS_OPTIONAL_GROUPS+=	ssl
PKG_OPTIONS_GROUP.ssl=		gnutls openssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_GNUTLS=ON
.else
CMAKE_ARGS+=	-DWITH_GNUTLS=OFF
.endif

.if !empty(PKG_OPTIONS:Minet6)
CMAKE_ARGS+=	-DWITH_IPv6=ON
.else
CMAKE_ARGS+=	-DWITH_IPv6=OFF
.endif

.if !empty(PKG_OPTIONS:Mlibgcrypt)
.include "../../security/libgcrypt/buildlink3.mk"
CMAKE_ARGS+=		-DWITH_GCRYPT=ON
.else
CMAKE_ARGS+=		-DWITH_GCRYPT=OFF
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_OPENSSL=ON
.else
CMAKE_ARGS+=	-DWITH_OPENSSL=OFF
.endif

.if !empty(PKG_OPTIONS:Msasl)
.include "../../security/cyrus-sasl/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_SASL=ON
.else
CMAKE_ARGS+=	-DWITH_SASL=OFF
.endif
