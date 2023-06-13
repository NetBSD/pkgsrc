# $NetBSD: options.mk,v 1.6 2023/06/13 17:54:44 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libssh
PKG_SUPPORTED_OPTIONS=		gssapi
PKG_OPTIONS_REQUIRED_GROUPS=	crypto
PKG_OPTIONS_GROUP.crypto=	openssl libgcrypt
PKG_SUGGESTED_OPTIONS=		gssapi openssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgssapi)
CMAKE_ARGS+=		-DWITH_GSSAPI:BOOL=ON
.include "../../mk/krb5.buildlink3.mk"
.else
CMAKE_ARGS+=		-DWITH_GSSAPI:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
CMAKE_ARGS+=		-DWITH_GCRYPT:BOOL=OFF
.include "../../security/openssl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibgcrypt)
BUILDLINK_API_DEPENDS.libgcrypt+=	libgcrypt>=1.4
CMAKE_ARGS+=		-DWITH_GCRYPT:BOOL=ON
.include "../../security/libgcrypt/buildlink3.mk"
.endif
