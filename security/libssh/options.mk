# $NetBSD: options.mk,v 1.3 2018/01/25 19:52:38 markd Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libssh
PKG_OPTIONS_REQUIRED_GROUPS=	crypto
PKG_OPTIONS_GROUP.crypto=	openssl libgcrypt
#PKG_SUPPORTED_OPTIONS=		compression
PKG_SUGGESTED_OPTIONS=		openssl # XXX zlib

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mzlib)
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2
CONFIGURE_ARGS+=		--with-libz=${BUILDLINK_PREFIX.zlib:Q}
.include "../../devel/zlib/buildlink3.mk"
.endif

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
