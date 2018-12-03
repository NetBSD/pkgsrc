# $NetBSD: options.mk,v 1.4 2018/12/03 15:19:51 adam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libssh
PKG_OPTIONS_REQUIRED_GROUPS=	crypto
PKG_OPTIONS_GROUP.crypto=	openssl libgcrypt
PKG_SUGGESTED_OPTIONS=		openssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenssl)
BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.8
CMAKE_ARGS+=		-DWITH_GCRYPT:BOOL=OFF
.include "../../security/openssl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibgcrypt)
BUILDLINK_API_DEPENDS.libgcrypt+=	libgcrypt>=1.4
CMAKE_ARGS+=		-DWITH_GCRYPT:BOOL=ON
.include "../../security/libgcrypt/buildlink3.mk"
.endif
