# $NetBSD: options.mk,v 1.5 2020/01/25 10:45:11 jperkin Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libssh
PKG_OPTIONS_REQUIRED_GROUPS=	crypto
PKG_OPTIONS_GROUP.crypto=	openssl libgcrypt
PKG_SUGGESTED_OPTIONS=		openssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenssl)
CMAKE_ARGS+=		-DWITH_GCRYPT:BOOL=OFF
.include "../../security/openssl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibgcrypt)
BUILDLINK_API_DEPENDS.libgcrypt+=	libgcrypt>=1.4
CMAKE_ARGS+=		-DWITH_GCRYPT:BOOL=ON
.include "../../security/libgcrypt/buildlink3.mk"
.endif
